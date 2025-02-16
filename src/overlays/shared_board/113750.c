
#include "common.h"
#include "../../board.h"
#include "../../player.h"
#include "../../process.h"

extern s8 D_800CB99C;

extern s32 D_801056C0;
extern f32 D_801056E8;
extern void *D_801056EC;

extern f32 func_800E8DC8_FC9E8();
extern struct process *func_800E8EDC_FCAFC(f32 arg0);
extern void func_800E98E8_FD508(void *arg0);

INCLUDE_ASM(s32, "overlays/shared_board/113750", func_800FFB30_113750);

INCLUDE_ASM(s32, "overlays/shared_board/113750", func_800FFD0C_11392C);

void func_800FFE90_113AB0(s32 arg0) {
    func_800479AC(D_801056C0);
    func_800F2CA4_1068C4(arg0);
}

INCLUDE_ASM(s32, "overlays/shared_board/113750", func_800FFEC4_113AE4);

INCLUDE_ASM(s32, "overlays/shared_board/113750", func_800FFF44_113B64);

INCLUDE_ASM(s32, "overlays/shared_board/113750", func_80100130_113D50);

void func_8010020C_113E2C() {
    func_800FFF44_113B64();
}

void func_80100228_113E48() {
    func_80100130_113D50();
    func_800F5DD8_1099F8();
}

INCLUDE_ASM(s32, "overlays/shared_board/113750", func_8010024C_113E6C);

void func_80100630_114250() {
    while (TRUE) {
        func_800E9748_FD368(&gPlayers[D_800CD058.current_player_index].obj->coords);
        SleepVProcess();
    }
}

// related to showing pause screen overlay.
void func_8010067C_11429C(s32 controller) {
    struct process *curProcess;
    struct process *process;

    D_801056E8 = func_800E8DC8_FC9E8();
    func_800E98E8_FD508(&D_801056EC);
    D_800CB99C = 1;
    func_80049FB8();
    func_800E6FCC_FABEC();
    process = InitProcess(func_80100630_114250, 0x1005, 0, 0);
    func_80047B80(process, 0x20);
    LinkChildProcess(GetCurrentProcess(), func_800E8EDC_FCAFC(1.0f));
    WaitForChildProcess();
    EndProcess(process);
    curProcess = GetCurrentProcess();
    process = InitProcess(func_8010024C_113E6C, 0x1005, 0, 0);
    process->user_data = controller;
    func_80047B80(process, 0x80);
    LinkChildProcess(curProcess, process);
    WaitForChildProcess();
    func_8004A0E0();
    D_800CB99C = 0;
    func_800E6FBC_FABDC();
}
