/* 1000:191c */

void FUN_1000_191c(void)

{
  undefined2 uVar1;
  uint uVar2;
  int in_CX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  uint uVar3;
  undefined2 unaff_DS;
  undefined1 uVar4;
  
code_r0x0001191c:
  *(undefined2 *)0x3e78 = 2;
  FUN_1000_0ccc();
  *(undefined2 *)&DAT_0000_3bc6 = 5;
  uVar1 = FUN_1000_5f7e();
  if (*(char *)0x34d6 != '\0') {
    FUN_1000_c5f4(uVar1);
  }
  FUN_1000_0ceb();
LAB_1000_193f:
  FUN_1000_1aa6();
  uVar3 = (uint)(byte)((char)(*(uint *)0x3bc4 / 10) - 1) * 2 + 0x10;
  if ((*(uint *)&DAT_0000_3bc6 & 0xfffe) != uVar3) {
    FUN_1000_0ccc();
    *(uint *)&DAT_0000_3bc6 = uVar3;
    FUN_1000_5f7e();
    FUN_1000_0ceb();
  }
  FUN_1000_7c9e();
  FUN_1000_72ad();
  FUN_1000_0d0a();
  uVar1 = *(undefined2 *)&DAT_0000_3bc6;
  *(uint *)&DAT_0000_3bc6 = *(uint *)&DAT_0000_3bc6 | 1;
  FUN_1000_5f7e();
  *(undefined2 *)&DAT_0000_3bc6 = uVar1;
  *(undefined1 *)0x32d4 = 0x1e;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
  *(undefined2 *)0x32ea = 0;
  *(undefined2 *)0x32ec = 0;
LAB_1000_1998:
  uVar3 = FUN_1000_c8d8();
  uVar2 = uVar3 & 0xff6f;
  if ((uVar3 & 0x6f) == 0) {
    if (*(char *)0x32d4 != '\0') goto LAB_1000_1998;
  }
  else {
    if ((*(byte *)0x3c00 < 4) && (*(undefined1 *)0x32d4 = 0x1e, (uVar3 & 0x20) != 0)) {
      if (*(byte *)0x3c00 < 4) {
        FUN_1000_0d12(uVar2);
        FUN_1000_20f0();
        FUN_1000_7c9e();
        FUN_1000_72ad();
        *(undefined1 *)0x32d4 = 0x1e;
      }
      goto LAB_1000_1998;
    }
    if ((uVar3 & 0x40) != 0) goto LAB_1000_1a9b;
    uVar4 = 0;
    if (*(char *)0x32e5 == '\0') {
      FUN_1000_9ab9();
      if ((in_CX != 0) && (FUN_1000_ad80(), !(bool)uVar4)) {
        *(undefined2 *)&DAT_0000_3be4 = extraout_DX;
        FUN_1000_9b42();
        *(undefined2 *)&DAT_0000_32bf = 0;
        if (3 < *(byte *)0x3c00) goto LAB_1000_1a34;
        FUN_1000_7c9e();
        FUN_1000_72ad();
        goto LAB_1000_1998;
      }
    }
    else {
      while( true ) {
        uVar4 = 0;
        if (((uVar2 & 0xf) == 0) || (FUN_1000_9ab9(), in_CX == 0)) goto LAB_1000_1a1b;
        FUN_1000_ad80();
        if ((bool)uVar4) break;
        *(undefined2 *)&DAT_0000_3be4 = extraout_DX_00;
        uVar2 = FUN_1000_c8d8();
      }
      *(undefined2 *)0x32e6 = 0;
      *(undefined2 *)0x32e8 = 0;
LAB_1000_1a1b:
      FUN_1000_9b42();
      *(undefined2 *)&DAT_0000_32bf = 0;
      if (*(byte *)0x3c00 < 4) {
        FUN_1000_7c9e();
        FUN_1000_72ad();
        goto LAB_1000_1998;
      }
    }
  }
LAB_1000_1a34:
  uVar4 = 0;
  if (*(char *)0x32d1 == '\0') {
    *(undefined1 *)0x32d1 = 8;
    *(char *)0x3be8 = *(char *)0x3be8 + '\x01';
    *(undefined2 *)0xc4f2 = *(undefined2 *)0x3c1e;
    FUN_1000_3332();
    FUN_1000_32cc();
    FUN_1000_a6a5();
    FUN_1000_a731();
    FUN_1000_7c9e();
    FUN_1000_72ad();
    FUN_1000_b102();
    FUN_1000_b2f2();
    if (((bool)uVar4) || (FUN_1000_b28d(), (bool)uVar4)) goto code_r0x0001191c;
    FUN_1000_a75d();
  }
  goto LAB_1000_1998;
LAB_1000_1a9b:
  FUN_1000_0d12(uVar2);
  goto LAB_1000_193f;
}


