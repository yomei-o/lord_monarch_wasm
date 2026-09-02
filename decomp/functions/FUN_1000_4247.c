/* 1000:4247 */

undefined4 __cdecl16near FUN_1000_4247(void)

{
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 in_DX;
  uint uVar4;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 == 1) {
    FUN_1000_9b34();
    if (((undefined *)&DAT_0000_d27e)[in_BX] == 'z') {
      uVar2 = (uint)(byte)((undefined *)&DAT_0000_d27f)[in_BX] + (*(uint *)(unaff_SI + 6) >> 5);
      if (0xff < uVar2) {
        uVar2 = 0xff;
      }
      ((undefined *)&DAT_0000_d27f)[in_BX] = (char)uVar2;
    }
    else {
      if (0xf < (byte)(((undefined *)&DAT_0000_d27e)[in_BX] - 0x20)) goto LAB_1000_42f4;
      uVar4 = (uint)(byte)((undefined *)&DAT_0000_d27f)[in_BX];
      uVar2 = *(uint *)(unaff_SI + 6) >> 5;
      if (uVar4 + 0xff < uVar2) {
        uVar2 = uVar4 + 0xff;
      }
      cVar3 = (char)(uVar4 - uVar2);
      if (uVar2 <= uVar4 && uVar4 - uVar2 != 0) {
        ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
        FUN_1000_9ae1();
        return CONCAT22(in_DX,in_AX);
      }
      *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x7a);
      FUN_1000_bcf4();
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) != 0) {
        FUN_1000_4924();
      }
    }
    FUN_1000_9ae1();
    return CONCAT22(in_DX,in_AX);
  }
LAB_1000_42f4:
  return CONCAT22(in_DX,in_AX);
}


