/**
 * @file
 * @brief Misc functions.
**/

#ifndef ITEMPROP_H
#define ITEMPROP_H

#include "itemprop-enum.h"

struct bolt;

void init_properties();

// cursed:
bool item_known_cursed(const item_def &item) PURE;
bool curse_an_item(bool ignore_holy_wrath = false);
void do_curse_item(item_def &item, bool quiet = true);
void do_uncurse_item(item_def &item, bool inscribe = true, bool no_ash = false,
                     bool check_bondage = true);

// stationary:
void set_net_stationary(item_def &item);
bool item_is_stationary(const item_def &item) PURE;
bool item_is_stationary_net(const item_def &item) PURE;
actor *net_holdee(const item_def &net);

// ident:
bool item_ident(const item_def &item, iflags_t flags) PURE;
void set_ident_flags(item_def &item, iflags_t flags);
void unset_ident_flags(item_def &item, iflags_t flags);
bool fully_identified(const item_def &item) PURE;

// item descriptions:
void     set_equip_desc(item_def &item, iflags_t flags);
iflags_t get_equip_desc(const item_def &item) PURE;

bool  is_helmet(const item_def &item) PURE;
bool  is_hard_helmet(const item_def &item) PURE;

// ego items:
bool set_item_ego_type(item_def &item, object_class_type item_type,
                       int ego_type);
brand_type get_weapon_brand(const item_def &item) PURE;
special_armour_type get_armour_ego_type(const item_def &item) PURE;
special_missile_type get_ammo_brand(const item_def &item) PURE;

// armour functions:
int armour_max_enchant(const item_def &item) PURE;
bool armour_is_hide(const item_def &item, bool inc_made = false) PURE;
bool armour_is_special(const item_def &item) PURE;

equipment_type get_armour_slot(const item_def &item) PURE;
equipment_type get_armour_slot(armour_type arm) IMMUTABLE;

bool jewellery_is_amulet(const item_def &item) PURE;
bool jewellery_is_amulet(int sub_type) IMMUTABLE;

bool  hide2armour(item_def &item);

int   fit_armour_size(const item_def &item, size_type size) PURE;
bool  check_armour_size(const item_def &item, size_type size) PURE;

bool item_is_rechargeable(const item_def &it, bool hide_charged = false) PURE;
int wand_charge_value(int type) PURE;
int wand_max_charges(int type) PURE;
bool is_offensive_wand(const item_def &item) PURE;
bool is_enchantable_armour(const item_def &arm, bool uncurse,
                           bool unknown = false) PURE;

bool is_shield(const item_def &item) PURE;
bool is_shield_incompatible(const item_def &weapon,
                            const item_def *shield = NULL) PURE;
bool shield_reflects(const item_def &shield) PURE;
void ident_reflector(item_def *item);

// Only works for armour/weapons/missiles
// weapon functions:
int weapon_rarity(int w_type) IMMUTABLE;

int   cmp_weapon_size(const item_def &item, size_type size) PURE;
bool  is_weapon_wieldable(const item_def &item, size_type size) PURE;

hands_reqd_type basic_hands_reqd(const item_def &item, size_type size) PURE;
hands_reqd_type hands_reqd(const actor* ac, object_class_type base_type, int sub_type);

bool is_giant_club_type(int wpn_type) IMMUTABLE;
bool is_ranged_weapon_type(int wpn_type) IMMUTABLE;
bool is_blessed_weapon_type(int wpn_type) IMMUTABLE;
bool is_demonic_weapon_type(int wpn_type) IMMUTABLE;
bool is_magic_weapon_type(int wpn_type) IMMUTABLE;

bool is_melee_weapon(const item_def &weapon) PURE;
bool is_demonic(const item_def &item) PURE;
bool is_blessed(const item_def &item) PURE;
bool is_blessed_convertible(const item_def &item) PURE;
bool convert2good(item_def &item);
bool convert2bad(item_def &item);

int get_vorpal_type(const item_def &item) PURE;
int get_damage_type(const item_def &item) PURE;
int single_damage_type(const item_def &item) PURE;

bool is_brandable_weapon(const item_def &wpn, bool allow_ranged, bool divine = false);

int weapon_str_weight(const item_def &wpn) PURE;

skill_type item_attack_skill(const item_def &item) PURE;
skill_type item_attack_skill(object_class_type wclass, int wtype) IMMUTABLE;

bool item_skills(const item_def &item, set<skill_type> &skills);

// launcher and ammo functions:
bool is_range_weapon(const item_def &item) PURE;
missile_type fires_ammo_type(const item_def &item) PURE;
const char *ammo_name(missile_type ammo) IMMUTABLE;
const char *ammo_name(const item_def &bow) PURE;
bool has_launcher(const item_def &ammo) PURE;
bool is_throwable(const actor *actor, const item_def &wpn,
                  bool force = false) PURE;
launch_retval is_launched(const actor *actor, const item_def *launcher,
                          const item_def &missile) PURE;

bool ammo_always_destroyed(const item_def &missile) PURE;
bool ammo_never_destroyed(const item_def &missile) PURE;
int  ammo_type_destroy_chance(int missile_type) PURE;
int  ammo_type_damage(int missile_type) PURE;


reach_type weapon_reach(const item_def &item) PURE;

// Macguffins
bool item_is_rune(const item_def &item,
                  rune_type which_rune = NUM_RUNE_TYPES) PURE;
bool item_is_unique_rune(const item_def &item) PURE;
bool item_is_orb(const item_def &orb) PURE;
bool item_is_horn_of_geryon(const item_def &item) PURE;
bool item_is_spellbook(const item_def &item) PURE;

bool is_xp_evoker(const item_def &item);
bool evoker_is_charged(const item_def &item);

// ring functions:
bool ring_has_pluses(const item_def &item) PURE;
bool ring_has_stackable_effect(const item_def &item) PURE;

// food functions:
bool is_blood_potion(const item_def &item) PURE;
bool food_is_meaty(int food_type) PURE;
bool food_is_meaty(const item_def &item) PURE;
bool food_is_veggie(int food_type) PURE;
bool food_is_veggie(const item_def &item) PURE;
int food_value(const item_def &item) PURE;
int food_turns(const item_def &item) PURE;
bool can_cut_meat(const item_def &item) PURE;
bool is_fruit(const item_def &item) PURE;

// generic item property functions:
int get_armour_res_fire(const item_def &arm, bool check_artp) PURE;
int get_armour_res_cold(const item_def &arm, bool check_artp) PURE;
int get_armour_res_poison(const item_def &arm, bool check_artp) PURE;
int get_armour_res_elec(const item_def &arm, bool check_artp) PURE;
int get_armour_life_protection(const item_def &arm, bool check_artp) PURE;
int get_armour_res_magic(const item_def &arm, bool check_artp) PURE;
int get_armour_res_sticky_flame(const item_def &arm) PURE;
bool get_armour_see_invisible(const item_def &arm, bool check_artp) PURE;

int get_jewellery_res_fire(const item_def &ring, bool check_artp) PURE;
int get_jewellery_res_cold(const item_def &ring, bool check_artp) PURE;
int get_jewellery_res_poison(const item_def &ring, bool check_artp) PURE;
int get_jewellery_res_elec(const item_def &ring, bool check_artp) PURE;
int get_jewellery_life_protection(const item_def &ring, bool check_artp) PURE;
int get_jewellery_res_magic(const item_def &ring, bool check_artp) PURE;
bool get_jewellery_see_invisible(const item_def &ring, bool check_artp) PURE;

int property(const item_def &item, int prop_type) PURE;
bool gives_ability(const item_def &item) PURE;
bool gives_resistance(const item_def &item) PURE;
int item_mass(const item_def &item) PURE;
bool is_item_jelly_edible(const item_def &item);
equipment_type get_item_slot(object_class_type type, int sub_type) IMMUTABLE;
equipment_type get_item_slot(const item_def &item) PURE;

string item_base_name(const item_def &item);
string item_base_name(object_class_type type, int sub_type);
string food_type_name(int sub_type);
const char *weapon_base_name(weapon_type subtype) IMMUTABLE;
weapon_type name_nospace_to_weapon(string name_nospace);

void seen_item(const item_def &item);

static inline bool is_weapon(const item_def &item)
{
    return item.base_type == OBJ_WEAPONS
           || item.base_type == OBJ_STAVES
           || item.base_type == OBJ_RODS;
}

void remove_whitespace(string &str);
#endif
