#ifndef MIMIC_H
#define MIMIC_H

#include "ultra64.h"
#include "unk.h"

struct ai_t;
struct cursor_t;
struct struct_gInfo_unk_00068;
struct tetWell;

// void func_80083050_usa();
// void func_8008336C_usa();
// void func_800833B0_usa();
void UpdateMT(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
void UpdateMTController(struct tetWell *well, struct cursor_t *cursor, s32 num);
void DoMT(void);
void MimicCheckState(struct tetWell *well, struct cursor_t *cursor);
// void func_80084C18_usa();
// void func_80084C84_usa();
// void func_80084D24_usa();
// void func_80084D84_usa();
// void func_8008554C_usa();
// void func_80085CC8_usa();
void DrawMT(struct struct_gInfo_unk_00068 *arg0);
void DoMimic(void);
void InitMimic(void);

#endif
