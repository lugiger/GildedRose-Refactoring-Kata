#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

void GildedRose::updateQuality() 
{
    for (Item & item : items) {
        updateItem(item);
    }
}

void GildedRose::updateItem(Item & item)
{
    updateItemQuality(item);
    updateItemSellIn(item);
    updateItemQualityPostSellIn(item);
}

void GildedRose::updateItemQuality(Item & item)
{
    if (item.name == "Aged Brie")
    {
        incrementQuality(item);
    }
    else if (item.name == "Backstage passes to a TAFKAL80ETC concert")
    {
        incrementQuality(item);
        if (item.sellIn < 11)
        {
            incrementQuality(item);
        }

        if (item.sellIn < 6)
        {
            incrementQuality(item);
        }
    }
    else if (item.name == "Sulfuras, Hand of Ragnaros")
    {
        return;
    }
    else if (item.name == "Conjured Mana Cake")
    {
        decrementQuality(item);
        decrementQuality(item);
    }
    else
    {
        decrementQuality(item);
    }
}

void GildedRose::incrementQuality(Item & item)
{
    if (item.quality < 50)
    {
        item.quality = item.quality + 1;
    }
}

void GildedRose::decrementQuality(Item & item)
{
    if (item.quality > 0)
    {
        item.quality = item.quality - 1;
    }
}

void GildedRose::updateItemSellIn(Item & item)
{
    if (item.name != "Sulfuras, Hand of Ragnaros")
    {
        item.sellIn = item.sellIn - 1;
    }
}

void GildedRose::updateItemQualityPostSellIn(Item & item)
{
    if (item.sellIn < 0)
    {
        if (item.name == "Aged Brie")
        {
            incrementQuality(item);
        }
        else if (item.name == "Backstage passes to a TAFKAL80ETC concert")
        {
            item.quality = 0;
        }
        else if (item.name == "Sulfuras, Hand of Ragnaros")
        {
            return;
        }
        else if (item.name == "Conjured Mana Cake")
        {
            decrementQuality(item);
            decrementQuality(item);
        }
        else
        {
            decrementQuality(item);
        }
    }
}
