/* 1000:69df */

undefined4 __cdecl16near FUN_1000_69df(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 in_DX;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  if ((((undefined *)&DAT_0000_32f2)[(uint)*(byte *)&DAT_0000_3e80 * 2] & 8) != 0) {
    FUN_1000_705b();
    bVar5 = false;
    uVar3 = 0x800;
    uVar2 = *(undefined4 *)0x3e86;
    pcVar1 = (code *)swi(0x1b);
    (*pcVar1)();
    *(undefined1 *)0x3e92 = extraout_AH;
    if (!bVar5) {
      bVar5 = CARRY2((uint)uVar2,uVar3);
      uVar4 = 0xc00;
      pcVar1 = (code *)swi(0x1b);
      (*pcVar1)();
      *(undefined1 *)0x3e92 = extraout_AH_00;
      if (!bVar5) {
        bVar5 = CARRY2((uint)uVar2 + uVar3,uVar4);
        pcVar1 = (code *)swi(0x1b);
        (*pcVar1)();
        *(undefined1 *)0x3e92 = extraout_AH_01;
        if (!bVar5) {
          ((undefined *)&DAT_0000_32f2)[(uint)*(byte *)&DAT_0000_3e80 * 2] = 0;
        }
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}


