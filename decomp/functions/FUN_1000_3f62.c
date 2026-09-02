/* 1000:3f62 */

undefined4 __cdecl16near FUN_1000_3f62(void)

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
  bool bVar5;
  
  iVar1 = FUN_1000_aa93();
  if (iVar1 == 0) {
    FUN_1000_4947();
    return CONCAT22(in_DX,in_AX);
  }
  if (iVar1 != 1) {
LAB_1000_402c:
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_9b34();
  cVar3 = ((undefined *)&DAT_0000_d27e)[in_BX];
  if (cVar3 == '{') {
    uVar4 = -((byte)((undefined *)&DAT_0000_d27f)[in_BX] - 0xff);
    uVar2 = *(uint *)(unaff_SI + 6) >> 4;
    if (uVar4 < uVar2) {
      uVar2 = uVar4;
    }
    bVar5 = (uVar2 >> 1 & 1) != 0;
    FUN_1000_abc7();
    if (!bVar5) {
      ((undefined *)&DAT_0000_d27f)[in_BX] = ((undefined *)&DAT_0000_d27f)[in_BX] + (char)uVar2;
      goto LAB_1000_4011;
    }
  }
  else {
    if (cVar3 != '\0') {
      if (3 < (byte)(cVar3 - 0xcU)) goto LAB_1000_402c;
      if (*(int *)((undefined *)&DAT_0000_e47e + in_BX) != 0) goto LAB_1000_4025;
    }
    uVar4 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] + 0xff;
    uVar2 = *(uint *)(unaff_SI + 6) >> 4;
    if (uVar4 < uVar2) {
      uVar2 = uVar4;
    }
    bVar5 = (uVar2 >> 1 & 1) != 0;
    FUN_1000_abc7();
    if (!bVar5) {
      iVar1 = (byte)((undefined *)&DAT_0000_d27f)[in_BX] - uVar2;
      cVar3 = (char)iVar1;
      if (uVar2 <= (byte)((undefined *)&DAT_0000_d27f)[in_BX] && iVar1 != 0) {
        ((undefined *)&DAT_0000_d27f)[in_BX] = cVar3;
        FUN_1000_9ae1();
        return CONCAT22(in_DX,in_AX);
      }
      *(uint *)((undefined *)&DAT_0000_d27e + in_BX) = CONCAT11(-cVar3,0x7b);
      FUN_1000_bcf4();
LAB_1000_4011:
      FUN_1000_9ae1();
      return CONCAT22(in_DX,in_AX);
    }
  }
LAB_1000_4025:
  return CONCAT22(in_DX,in_AX);
}


