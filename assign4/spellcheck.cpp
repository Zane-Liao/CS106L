#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

// Corpus = std::set<Token>
Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  Corpus tokens;
  // dentify all iterators to space characters
  // 1.find_all and isspace
  // lamada function: []() {}
  auto text_source = find_all(source.begin(), source.end(), ::isspace);

  // 2.Generate tokens between consecutive space characters
  // Tokens
  std::transform(text_source.begin(), text_source.end()-1, text_source.begin()+1,
              std::inserter(tokens, tokens.end()), [&source]( 
                auto it1, 
                auto it2){
    return Token(source, it1, it2);
  });

  // 3.Get rid of empty tokens
  std::erase_if(tokens, [](const Token& t) -> bool { return t.content.empty(); } );

  return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  // 1.Skip words that are already correctly spelled.
  // 2.Find one-edit-away words in the dictionary using Damerau-Levenshtein.
  namespace rv = std::ranges::views;
  auto skip_words = [&dictionary](const Token& t) { 
    return !dictionary.contains(t.content); 
  };
  auto find_words = [&dictionary](const Token& t) {
    auto leven = ([&t](auto& b) {
      return levenshtein(t.content, b) == 1;
    });
    auto view = dictionary | rv::filter(leven);
    std::set<std::string> suggestions(view.begin(), view.end());
    return Mispelling{t, suggestions};
  };
  auto view = source | rv::filter(skip_words)
                     | rv::transform(find_words);
  // 3.Drop misspellings with no suggestions.
  auto v = view | rv::filter([](const Mispelling& t){
    return !t.suggestions.empty(); 
  });

  return std::set<Mispelling>(v.begin(), v.end());
};

/* Helper methods */

#include "utils.cpp"