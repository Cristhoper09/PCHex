#include <3ds.h>
#include "state.h"

void 	pkmGenSpecies(t_stinf *state)
{
  if (stdInputField(state, 0, 1, 0, 0)) return;
}

void 	pkmGenNickname(t_stinf *state)
{
  u32 	kPressed = state->kPressed;

  if (stdInputField(state, -1, 1, 0, 0)) return;
  if (kPressed & KEY_X) {setNickname((char *) pkData.species[state->pkm.pkx.species], &state->pkm); state->modded = 1;}
}

void 	pkmGenPID(t_stinf *state)
{
  if (dirInputField(state, 2, 16, 0, 0)) return;

  u32 	kPressed = state->kPressed;
  if (kPressed & KEY_X) {rerollPIDspe(&state->pkm, 2, state->pkm.gender); state->modded = 1;}
  if (kPressed & KEY_Y) {rerollPIDspe(&state->pkm, 1, state->pkm.gender); state->modded = 1;}
}

void 	pkmGenGender(t_stinf *state)
{
  if (dirInputField(state, 3, 4, 0, 0)) return;

  u32 kPressed = state->kPressed;
  if (kPressed & KEY_X)
  {
    if (state->pkm.gender == 2)
      return;
    if (pkData.pkmData[state->pkm.pkx.species][0xA] == 0 ||
	pkData.pkmData[state->pkm.pkx.species][0xA] >= 254)
      return;
    rerollPIDspe(&state->pkm, state->pkm.isShiny, !state->pkm.gender);
    state->modded = 1;
  }
}

void 	pkmGenEXP(t_stinf *state)
{
  u32 	kPressed = state->kPressed;
  if (dirInputField(state, 16, 5, 0, 0)) return;

  s8 	addLevel = 0;
  if (kPressed & KEY_UP)
    addLevel += 1;
  if (kPressed & KEY_DOWN)
    addLevel -= 1;
  if (addLevel)
  {
    setPkmLevel(&state->pkm, state->pkm.level + addLevel);
    state->modded = 1;
  }
}

void 	pkmGenOT(t_stinf *state)
{
  if (stdInputField(state, -1, 2, 0, 1)) return;
}

void 	pkmGenHandler(t_stinf *state)
{
  if (stdInputField(state, -2, 2, -1, 0)) return;
}

void 	pkmGenTrainerFrd(t_stinf *state)
{
  if (stdInputField(state, -2, 2, 0, 1)) return;

  s8 	addFrd = 0;
  u32 	kPressed = state->kPressed;

  if (kPressed & KEY_RIGHT) addFrd += 10;
  if (kPressed & KEY_LEFT) addFrd -= 10;
  if (kPressed & KEY_UP) addFrd++;
  if (kPressed & KEY_DOWN) addFrd--;
  if (addFrd) state->modded = 1;
  state->pkm.pkx.trainerFriendship = (s8)state->pkm.pkx.trainerFriendship + addFrd;
}

void 	pkmGenHandlerFrd(t_stinf *state)
{
  if (stdInputField(state, -2, 1, -1, 0)) return;

  s8 	addFrd = 0;
  u32 	kPressed = state->kPressed;

  if (kPressed & KEY_RIGHT) addFrd += 10;
  if (kPressed & KEY_LEFT) addFrd -= 10;
  if (kPressed & KEY_UP) addFrd++;
  if (kPressed & KEY_DOWN) addFrd--;
  if (addFrd) state->modded = 1;
  state->pkm.pkx.handlerFriendship = (s8)state->pkm.pkx.handlerFriendship + addFrd;
}

void 	pkmGenTrainerID(t_stinf *state)
{
  if (stdInputField(state, -2, 1, 0, 0)) return;
}

void 	pkmGenSID(t_stinf *state)
{
  if (stdInputField(state, -1, 1, 0, 0)) return;
}

void 	pkmGenMetLocation(t_stinf *state)
{
  if (stdInputField(state, -1, 1, 0, 0)) return;
}

void 	pkmGenMetDate(t_stinf *state)
{
  if (stdInputField(state, -1, 1, 0, 0)) return;
}

void 	pkmGenOrigGame(t_stinf *state)
{
  if (stdInputField(state, -1, 1, 0, 0)) return;
}

void 	pkmGenHeldItem(t_stinf *state)
{
  if (stdInputField(state, -1, 1, 0, 0)) return;
}

void 	pkmGenPokeball(t_stinf *state)
{
  if (stdInputField(state, -1, 0, 0, 0)) return;
}

void 	pkmGenInputField(t_stinf *state)
{
  switch (state->inState){
    case 1: pkmGenSpecies(state); break;
    case 2: pkmGenNickname(state); break;
    case 3: pkmGenPID(state); break;
    case 4: pkmGenEXP(state); break;
    case 5: pkmGenOT(state); break;
    case 6: pkmGenHandler(state); break;
    case 7: pkmGenTrainerFrd(state); break;
    case 8: pkmGenHandlerFrd(state); break;
    case 9: pkmGenTrainerID(state); break;
    case 10: pkmGenSID(state); break;
    case 11: pkmGenMetLocation(state); break;
    case 12: pkmGenMetDate(state); break;
    case 13: pkmGenOrigGame(state); break;
    case 14: pkmGenHeldItem(state); break;
    case 15: pkmGenPokeball(state); break;
    case 16: pkmGenGender(state); break;

  }
}
