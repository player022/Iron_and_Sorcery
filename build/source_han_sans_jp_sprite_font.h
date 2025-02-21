// Source Han Sans 14px

#ifndef SOURCE_HAN_SANS_JP_SPRITE_FONT_H
#define SOURCE_HAN_SANS_JP_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"
#include "bn_sprite_items_source_han_sans_jp.h"

constexpr bn::utf8_character source_han_sans_jp_sprite_font_utf8_characters[] = {
    "军", "刀", "果", "浆"
};

constexpr bn::span<const bn::utf8_character> source_han_sans_jp_sprite_font_utf8_characters_span(
        source_han_sans_jp_sprite_font_utf8_characters);

constexpr auto source_han_sans_jp_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<source_han_sans_jp_sprite_font_utf8_characters_span>();

constexpr int8_t source_han_sans_jp_sprite_font_character_widths[] = {
    5, 4, 5, 7, 7, 11, 8, 3, 4, 5, 6, 7, 4, 5, 4, 6, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 4, 5, 7, 7, 7, 5, 10, 8, 7, 7, 7, 6, 6, 7, 7, 3, 6, 7, 6, 8, 7, 8, 7, 8, 8, 7, 7, 7, 8, 10, 8, 7, 7, 4, 6, 5, 6, 8, 6, 6, 7, 6, 6, 6, 6, 8, 6, 4, 6, 7, 4, 9, 6, 6, 7, 6, 5, 6, 6, 6, 7, 10, 7, 7, 6, 5, 3, 5, 7, 10, 10, 12, 10
};

constexpr bn::sprite_font source_han_sans_jp_sprite_font(
        bn::sprite_items::source_han_sans_jp,
        source_han_sans_jp_sprite_font_utf8_characters_map.reference(),
        source_han_sans_jp_sprite_font_character_widths);

#endif