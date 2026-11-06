#include <print>
#include <variant>
#include <vector>

struct Player {};

struct NPC {};

struct Enemy {};

using Units = std::vector<std::variant<Player, NPC, Enemy>>;

template <class... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

int main() {
    Units units;

    units.push_back(Player{});
    units.push_back(NPC{});
    units.push_back(Enemy{});

    for (const auto& unit : units) {
        std::visit(overloaded{[](const Player&) { std::println("Player"); },
                              [](const NPC&) { std::println("NPC"); },
                              [](const Enemy&) { std::println("Enemy"); }},
                   unit);
    }
}
