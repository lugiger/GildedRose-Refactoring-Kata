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

/* Probably a more modulaer approach would be better, as it is easier to extend
 * and add more item types
 */

class ItemUpdater
{
    protected:
        virtual void updateItemQuality(Item & item);
        virtual void updateItemSellIn(Item & item);
        virtual void updateItemQualityPostSellIn(Item & item);
        void changeQuality(Item & item, int amount);
    public:
        void updateItem(Item & item);
        ItemUpdater() {}
};

class GildedRose
{
private:
    ItemUpdater * getUpdater(Item & item);
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);

    void updateQuality();
};

class BackstagePassItemUpdater: public ItemUpdater
{
    public:
        BackstagePassItemUpdater() {}
    protected:
        void updateItemQuality(Item & item);
        void updateItemQualityPostSellIn(Item & item);
};

class BrieItemUpdater: public ItemUpdater
{
    public:
        BrieItemUpdater() {}
    protected:
        void updateItemQuality(Item & item);
        void updateItemQualityPostSellIn(Item & item);
};

class HandOfSulfurasItemUpdater: public ItemUpdater
{
    public:
        HandOfSulfurasItemUpdater() {}
    protected:
        void updateItemQuality(Item & item);
        void updateItemSellIn(Item & item);
        void updateItemQualityPostSellIn(Item & item);
};


class ConjuredItemUpdater: public ItemUpdater
{
    public:
        ConjuredItemUpdater() {}
    protected:
        void updateItemQuality(Item & item);
        void updateItemQualityPostSellIn(Item & item);
};
