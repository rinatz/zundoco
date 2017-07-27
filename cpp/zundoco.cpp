#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <deque>

template <typename R>
typename R::value_type choice(const R& range) {
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_real_distribution<> dist(0, range.size());
    auto iter = range.begin();

    const auto index = static_cast<int>(dist(engine));

    std::advance(iter, index);

    return *iter;
}

void sleep(const std::chrono::milliseconds& milliseconds) {
    const auto start = std::chrono::system_clock::now();

    while (true) {
        const auto end = std::chrono::system_clock::now();
        const auto elapsed
            = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        if (elapsed >= milliseconds) {
            return;
        }
    }

    return;
}

void zundoco() {
    const std::vector<std::string> choices = {
        u8"ズン", u8"ドコ"
    };
    const std::vector<std::string> expected = {
        u8"ズン", u8"ズン", u8"ズン", u8"ズン", u8"ドコ"
    };
    const std::vector<std::string> finish = {
        u8"キ・", u8"ヨ・", u8"シ！"
    };

    std::deque<std::string> words(expected.size());

    for (auto&& word : words) {
        word = choice(choices);
    }

    while (true) {
        if (std::equal(words.begin(), words.end(), expected.begin())) {
            auto milliseconds = std::chrono::milliseconds(1200);

            for (const auto& word : words) {
                std::cout << word << std::endl;
                sleep(milliseconds);
                milliseconds = std::chrono::milliseconds(600);
            }

            for (const auto& word : finish) {
                std::cout << word << std::flush;
                sleep(std::chrono::milliseconds(300));
            }

            std::cout << std::endl;

            return;
        }

        std::cout << words.front() << std::endl;

        words.pop_front();
        words.push_back(choice(choices));
    }
}

int main() {
    zundoco();

    return 0;
}
