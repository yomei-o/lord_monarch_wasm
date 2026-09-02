/* 1000:22de */

undefined4 __cdecl16near FUN_1000_22de(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 uVar4;
  int in_CX;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
LAB_1000_22df:
  do {
    FUN_1000_9b34();
    iVar3 = FUN_1000_aad5();
    if ((bool)in_CF) {
      iVar3 = 1;
    }
    *(int *)0x3ea2 = iVar3 + -1;
    *(undefined2 *)&DAT_0000_32bf = 0;
    FUN_1000_7c9e();
    FUN_1000_5c2e();
    FUN_1000_72ad();
    do {
      do {
        bVar1 = FUN_1000_c8d8();
        bVar2 = bVar1 & 0x6f;
      } while (bVar2 == 0);
      if (((bVar1 & 0x20) != 0) || ((bVar1 & 0x40) != 0)) {
        return CONCAT22(in_DX,in_AX);
      }
      in_CF = 0;
      if (*(char *)0x32e5 != '\0') goto LAB_1000_2336;
      FUN_1000_9ab9();
    } while ((in_CX == 0) || (FUN_1000_ad80(), (bool)in_CF));
    *(undefined2 *)&DAT_0000_3be4 = extraout_DX;
    uVar4 = FUN_1000_9b42();
    FUN_1000_0d12(uVar4);
  } while( true );
LAB_1000_2336:
  in_CF = 0;
  if (((bVar2 & 0xf) == 0) || (FUN_1000_9ab9(), in_CX == 0)) goto LAB_1000_235b;
  FUN_1000_ad80();
  if (!(bool)in_CF) {
    *(undefined2 *)&DAT_0000_3be4 = extraout_DX_00;
    bVar2 = FUN_1000_c8d8();
    goto LAB_1000_2336;
  }
  in_CF = 0;
  *(undefined2 *)0x32e6 = 0;
  *(undefined2 *)0x32e8 = 0;
LAB_1000_235b:
  FUN_1000_9b42();
  goto LAB_1000_22df;
}


