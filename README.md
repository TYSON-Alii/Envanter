## Envanter

```cpp
#include "envanter.hpp"
#include "magic_enum.hpp" // https://github.com/Neargye/magic_enum
enum class Meyve : unsigned char {
    None,
    Elma,
    Armut,
    Cilek
};
using enum Meyve;

auto main() -> int {
    envanter<Meyve, 10u> env;
    env.push(Elma, 5);
    env.push(Armut, 3);
    env.push(Armut, 2);
    env.push(Cilek, 12);
    env.push(Elma, 2);
    env.swap(1, 7);
    for (const auto& [item, count] : env.data)
        std::cout << magic_enum::enum_name(item) << ": " << count << ".\n";
};
```
#### Output:
Elma: 7.
None: 0.
Cilek: 12.
None: 0.
None: 0.
None: 0.
None: 0.
Armut: 5.
None: 0.
None: 0.
