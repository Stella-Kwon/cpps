#include "Span.hpp"

Span::Span():_max_size(0){};

Span::~Span(){};

Span::Span(unsigned int n):_max_size(n){};

Span::Span(const Span &other):_max_size(other._max_size){
    container = other.container;
}

Span &Span::operator=(const Span &other):_max_size(other._max_size)
{
    if (this != &other)
    {
        container = other.container;
    }
    return *this;
}

void Span::addNumber(int num){
    if (container.size() >= _max_size)
        throw std::runtime_error("Cannot add more numbers, maximum size reached");
    container.push_back(num);
}

int Span::shortestSpan()
{
    if (container.size() < 2)
      throw std::runtime_error("Not enough elements to find shortestspan");
    std:: vector<int>sorted_container = container;
    std::sort(sorted_container.begin(), sorted_container.end());

    int min_span = std::numeric_limits<int>::max();
    for(size_t i = 1; i < sorted_container.size(); ++i)
    {
        int span = sorted_container[i] - sorted_container[i - 1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

// int Span::shortestSpan()
// {
//     if (container.size() < 2)
//         throw std::runtime_error ("Not enough elements to find shortestspan");
//     std::vector<int> sorted_container = container;
//     std::ranges::sort(sorted_container);

//     //this will be a new container that will hold a span of two num
//     //view will just referal the vector not creating new (pair of) vector.
//     // it will do lazy evaluation in which it will start to do the action when it calls the action of the container.
//     // so view is just an recipe what it will do the action by then when real action starts.
//     auto adjacent_diffs = sorted_container
//     | std::views::adjacent<2>
//     | std::views::transform([](auto pair){return pair[1] - pair[0];});

//     return *std::ranges::min_element(adjacent_diffs);//the real action.
// }

int Span::longestSpan()
{
    if (container.size() < 2)
        throw std::runtime_error("Not enough elements to find longestspan");
    auto [min_it, max_it] = std::ranges::minmax_element(container); // it will return the two pointer value
    return *max_it - *min_it;
}



