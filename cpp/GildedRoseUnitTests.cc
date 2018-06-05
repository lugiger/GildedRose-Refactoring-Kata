#include <gtest/gtest.h>

#include "GildedRose.h"

TEST(GildedRoseQualityTest, AgedBrie) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 2, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(1, app.items[0].quality);
}

TEST(GildedRoseQualityTest, AgedBriePostSellin) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", -1, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(7, app.items[0].quality);
}

TEST(GildedRoseQualityTest, AgedBrieMaxQuality) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", -1, 49));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(50, app.items[0].quality);
}

TEST(GildedRoseQualityTest, NormalItem) {
    vector<Item> items;
    items.push_back(Item("Elixir of the Mongoose", 1, 7));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(6, app.items[0].quality);
}

TEST(GildedRoseQualityTest, NormalItemPostSellIn) {
    vector<Item> items;
    items.push_back(Item("Elixir of the Mongoose", 0, 7));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(5, app.items[0].quality);
}

TEST(GildedRoseQualityTest, BackstagePassMoreThan10) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 11, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(6, app.items[0].quality);
}

TEST(GildedRoseQualityTest, BackstagePassMoreThan5) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 6, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(7, app.items[0].quality);
}

TEST(GildedRoseQualityTest, BackstagePassMoreThan0) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 1, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(8, app.items[0].quality);
}

TEST(GildedRoseQualityTest, BackstagePass0) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseQualityTest, BackstagePassNegative) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", -1, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseQualityTest, Conjureditem) {
    vector<Item> items;
    items.push_back(Item("Conjured Mana Cake", 5, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(3, app.items[0].quality);
}

TEST(GildedRoseQualityTest, ConjureditemPostSellIn) {
    vector<Item> items;
    items.push_back(Item("Conjured Mana Cake", 0, 5));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(1, app.items[0].quality);
}

TEST(GildedRoseSellInTest, NormalItemPostSellIn) {
    vector<Item> items;
    items.push_back(Item("Elixir of the Mongoose", 0, 7));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-1, app.items[0].sellIn);
}

TEST(GildedRoseSellInTest, NormalItemSellIn) {
    vector<Item> items;
    items.push_back(Item("Elixir of the Mongoose", 2, 7));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(1, app.items[0].sellIn);
}

TEST(GildedRoseSellInTest, SulfurasSellIn) {
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].sellIn);
}

TEST(GildedRoseSellInTest, SulfurasPostSellIn) {
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-1, app.items[0].sellIn);
}

void example()
{
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    app.updateQuality();
}
