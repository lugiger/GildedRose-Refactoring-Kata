#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

ItemUpdater * GildedRose::getUpdater(Item & item)
{
    if (item.name == "Aged Brie")
    {
        return new BrieItemUpdater;
    }
    else if (item.name == "Backstage passes to a TAFKAL80ETC concert")
    {
        return new BackstagePassItemUpdater;
    }
    else if (item.name == "Sulfuras, Hand of Ragnaros")
    {
        return new HandOfSulfurasItemUpdater;
    }
    else if (item.name == "Conjured Mana Cake")
    {
        return new ConjuredItemUpdater;
    }
    else
    {
        return new ItemUpdater;
    }
}

void GildedRose::updateQuality() 
{
    for (Item & item : items) {
        ItemUpdater * updater = getUpdater(item);
        updater->updateItem(item);
    }
}

void ItemUpdater::updateItem(Item & item)
{
    updateItemQuality(item);
    updateItemSellIn(item);
    if (item.sellIn < 0)
        updateItemQualityPostSellIn(item);
}

void ItemUpdater::updateItemQuality(Item & item)
{
    changeQuality(item, -1);
}

void BrieItemUpdater::updateItemQuality(Item & item)
{
    changeQuality(item, 1);
}

void BackstagePassItemUpdater::updateItemQuality(Item & item)
{
    changeQuality(item, 1);
    if (item.sellIn < 11)
    {
        changeQuality(item, 1);
    }

    if (item.sellIn < 6)
    {
        changeQuality(item, 1);
    }
}

void ConjuredItemUpdater::updateItemQuality(Item & item)
{
    changeQuality(item, -2);
}

void HandOfSulfurasItemUpdater::updateItemQuality(Item & item) {}

void ItemUpdater::changeQuality(Item & item, int amount)
{
    item.quality += amount;
    if (item.quality > 50)
        item.quality = 50;
    if (item.quality < 0)
        item.quality = 0;
}

void ItemUpdater::updateItemSellIn(Item & item)
{
        item.sellIn = item.sellIn - 1;
}

void HandOfSulfurasItemUpdater::updateItemSellIn(Item & item) {}

void ItemUpdater::updateItemQualityPostSellIn(Item & item)
{
    changeQuality(item, -1);
}

void BrieItemUpdater::updateItemQualityPostSellIn(Item & item)
{
    changeQuality(item, 1);
}

void BackstagePassItemUpdater::updateItemQualityPostSellIn(Item & item)
{
    item.quality = 0;
}

void ConjuredItemUpdater::updateItemQualityPostSellIn(Item & item)
{
    changeQuality(item, -2);
}

void HandOfSulfurasItemUpdater::updateItemQualityPostSellIn(Item & item) {}
