template <typename enum_type, int n, enum_type empty_item>
class envanter {
private:
    typedef pair<enum_type, size_t> item_t;
    std::array<item_t, n> data;
public:
    inline auto& Data() { return data; };
    envanter() { std::fill(data.begin(), data.end(), make_pair(empty_item, 0)); };
    inline struct {
        enum_type item;
        int count;
    } operator[](int index) { return {data[index].first(), data[index].seconds()}; };
    int Add(enum_type item) {
        auto f = find_if(data.begin(), data.end(), [&](const item_t& i) -> bool { return i.first == item; });
        if (f != data.end()) {
            f->second++;
            return std::distance(data.begin(), f);
        }
        else {
            auto f = find_if(data.begin(), data.end(), [&](const item_t& i) -> bool { return i.first == empty_item; });
            if (f != data.end()) {
                *f = make_pair(item, 1);
                return std::distance(data.begin(), f);
            };
        };
        return -1;
    };
};
