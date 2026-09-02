/* 1000:7c9e */

undefined4 __cdecl16near FUN_1000_7c9e(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  int in_BX;
  undefined2 unaff_DS;
  
  if (*(int *)0x34c8 != 0) {
    FUN_1000_727a();
    if (*(int *)0x3bc4 == -1) {
      FUN_1000_7de8();
    }
    else {
      FUN_1000_7fa8();
    }
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_727a();
  if (*(int *)0x3bc2 == -1) {
    FUN_1000_7de8();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    FUN_1000_7aab();
    goto LAB_1000_7dcf;
  }
  if (*(int *)0x3288 == 1) {
    FUN_1000_81d6();
  }
  else if (*(int *)0x3288 == 2) {
    FUN_1000_83fb();
  }
  else {
    FUN_1000_7e3e();
  }
  FUN_1000_93c5();
  FUN_1000_7aab();
  FUN_1000_759b();
  FUN_1000_7aab();
  FUN_1000_759b();
  FUN_1000_7aab();
  FUN_1000_7aab();
  FUN_1000_9b34();
  if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0) {
    if (*(int *)&DAT_0000_32bf != 0) goto LAB_1000_7d1c;
  }
  else {
    *(int *)&DAT_0000_32bf = *(int *)((undefined *)&DAT_0000_e47e + in_BX);
LAB_1000_7d1c:
    FUN_1000_ac00();
    FUN_1000_8738();
    FUN_1000_c5bb();
    FUN_1000_759b();
    FUN_1000_759b();
  }
  FUN_1000_8756();
  FUN_1000_7aab();
  *(uint *)0x34c2 = (uint)(byte)((undefined *)&DAT_0000_d27f)[in_BX];
  *(undefined2 *)0x34c4 = *(undefined2 *)&DAT_0000_3be4;
  FUN_1000_759b();
  FUN_1000_7aab();
  FUN_1000_759b();
LAB_1000_7dcf:
  return CONCAT22(in_DX,in_AX);
}


