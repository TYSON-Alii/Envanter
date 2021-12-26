## Envanter

```cpp
#include <iostream>
#include "envanter.hpp"
#include "magic_enum.hpp" // https://github.com/Neargye/magic_enum

using namespace std;

enum meyve {
    empty,
    elma,
    armut,
    kiraz
};

int main() {
    envanter<meyve, 15, meyve::empty> env;
    env.Add(elma);
    env.Add(elma);
    env.Add(elma);
    env.Add(kiraz);
    env.Add(armut);
    env.Add(armut);

    for (auto& i : env.Data())
        cout << "type: " << magic_enum::enum_name(i.first) << ", count: " << i.second << '\n';

    return 0;
}
```
