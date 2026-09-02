/* 1000:a93f */

undefined2 __cdecl16near FUN_1000_a93f(void)

{
  undefined2 in_AX;
  byte extraout_AH;
  byte bVar1;
  byte extraout_AH_00;
  byte extraout_AH_01;
  byte extraout_AH_02;
  char in_DL;
  char extraout_DL;
  byte extraout_DL_00;
  byte extraout_DL_01;
  byte bVar2;
  char in_DH;
  byte extraout_DH;
  byte extraout_DH_00;
  byte bVar3;
  int in_BX;
  undefined2 unaff_DS;
  bool bVar4;
  
  bVar1 = 0;
  bVar4 = false;
  bVar3 = 0;
  if (in_DH != '\0') {
    FUN_1000_b494();
    in_DL = extraout_DL;
    bVar3 = extraout_DH;
    bVar1 = extraout_AH;
    if (bVar4) {
      bVar1 = extraout_AH | 1;
    }
  }
  bVar4 = false;
  bVar2 = 0;
  if (in_DL != '\0') {
    FUN_1000_b494();
    bVar2 = extraout_DL_00;
    bVar3 = extraout_DH_00;
    bVar1 = extraout_AH_00;
    if (bVar4) {
      bVar1 = extraout_AH_00 | 2;
    }
  }
  bVar4 = bVar3 < 0x2f;
  if (bVar4) {
    FUN_1000_b494();
    bVar2 = extraout_DL_01;
    bVar1 = extraout_AH_01;
    if (bVar4) {
      bVar1 = extraout_AH_01 | 4;
    }
  }
  bVar4 = bVar2 < 0x2f;
  if (bVar4) {
    FUN_1000_b494();
    bVar1 = extraout_AH_02;
    if (bVar4) {
      bVar1 = extraout_AH_02 | 8;
    }
  }
  ((undefined *)&DAT_0000_d27e)[in_BX] = bVar1 + 0x60;
  return in_AX;
}


