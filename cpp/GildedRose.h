#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
private:
    void updateItem(Item & item);
    void updateItemQuality(Item & item);
    void updateItemSellIn(Item & item);
    void updateItemQualityPostSellIn(Item & item);
    void incrementQuality(Item & item);
    void decrementQuality(Item & item);

public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);

    void updateQuality();
};

