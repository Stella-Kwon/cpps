#pragma once

#include <algorithm>
#include <ranges>
#include <vector>

class Span{

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end) {
          unsigned int count = std::distance(begin, end);
          if (container.size() + count > _max_size) {
            throw std::runtime_error(
                "Cannot add range: would exceed maximum size");
          }
          container.insert(container.end(), begin, end);
        }

      private:
        unsigned int _max_size;
        std::vector<int> container;
};
