/**
 * @file
 * @brief Monster spell casting.
**/

#ifndef MONCAST_H
#define MONCAST_H

#include "enum.h"

class monster;
struct bolt;

void init_mons_spells();
bool is_valid_mon_spell(spell_type spell);

bool has_push_space(const coord_def& pos, actor* act,
                    const vector<coord_def>* excluded = NULL);
bool get_push_space(const coord_def& pos, coord_def& newpos,
                    actor* act, bool ignore_tension = false,
                    const vector<coord_def>* excluded = NULL);

bool mons_should_cloud_cone(monster* agent, int power, const coord_def pos);

bool handle_mon_spell(monster* mons, bolt &beem);

bolt mons_spell_beam(monster* mons, spell_type spell_cast, int power,
                     bool check_validity = false);
void mons_cast(monster* mons, bolt &pbolt, spell_type spell_cast,
               unsigned short slot_flags, bool do_noise = true);
void mons_cast_noise(monster* mons, const bolt &pbolt,
                     spell_type spell_cast, unsigned short slot_flags);
bool setup_mons_cast(monster* mons, bolt &pbolt, spell_type spell_cast,
                     bool check_validity = false);

void mons_cast_haunt(monster* mons);
bool mons_word_of_recall(monster* mons, int recall_target);
void mons_cast_spectral_orcs(monster* mons);
void setup_breath_timeout(monster* mons);

monster* cast_phantom_mirror(monster* mons, monster* targ,
                             int hp_perc = 35,
                             int summ_type = SPELL_PHANTOM_MIRROR);
#endif
