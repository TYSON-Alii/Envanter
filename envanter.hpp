#include <iostream>
#include <array>
template <typename enum_type, size_t n, enum_type empty_item = (enum_type)0>
class envanter {
private:
    using uint = unsigned int;
    struct item_t {
        enum_type item = empty_item;
        uint count = 0;
    };
public:
    std::array<item_t, n> data;
    envanter() { std::fill(data.begin(), data.end(), item_t{ empty_item, 0 }); };
    inline item_t& operator[](const uint& index) { return data[index]; };
    uint push(enum_type item, const uint& count = 1u) {
        auto f = find_if(data.begin(), data.end(), [&](const item_t& i) -> bool { return i.item == item; });
        if (f != data.end()) {
            f->count += count;
            return std::distance(data.begin(), f);
        }
        else {
            auto f = find_if(data.begin(), data.end(), [&](const item_t& i) -> bool { return i.item == empty_item; });
            if (f != data.end()) {
                f->item = item;
                f->count = count;
                return std::distance(data.begin(), f);
            };
        };
        return -1;
    };
    bool pop(const uint& index, const uint& count = 1u) {
        if (data[index].count != 0u) {
            if (data[index].count > count)
                data[index].count -= count;
            else
                data[index].count = 0u;
            if (data[index].count == 0u) data[index].item = empty_item;
            return true;
        };
        return false;
    };
    void swap(const uint& index1, const uint& index2) { std::swap(data[index1], data[index2]); };
    void remove(const uint& index) { data[index] = { empty_item, 0 }; };
};
