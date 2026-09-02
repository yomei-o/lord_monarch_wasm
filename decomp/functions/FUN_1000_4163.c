/* 1000:4163 */

undefined2 __cdecl16near FUN_1000_4163(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  undefined2 in_AX;
  undefined2 uVar5;
  byte bVar6;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  bVar6 = ((undefined *)&DAT_0000_d27e)[in_BX] - 8;
  if (((bVar6 < 4) && (uVar5 = FUN_1000_a61d(), bVar6 != (byte)uVar5)) &&
     (bVar6 != (byte)((uint)uVar5 >> 8))) {
    bVar6 = ((undefined *)&DAT_0000_d27f)[in_BX];
    uVar5 = *(undefined2 *)(unaff_SI + 6);
    puVar1 = (uint *)(unaff_SI + 6);
    uVar4 = *puVar1;
    *puVar1 = *puVar1 - (uint)bVar6;
    if (uVar4 < bVar6 || *puVar1 == 0) {
      FUN_1000_4924();
    }
    bVar6 = (byte)uVar5;
    if ((char)((uint)uVar5 >> 8) == '\0') {
      pbVar2 = (undefined *)&DAT_0000_d27f + in_BX;
      bVar3 = *pbVar2;
      *pbVar2 = *pbVar2 - bVar6;
      if (bVar6 <= bVar3 && *pbVar2 != 0) {
        return in_AX;
      }
    }
    *(undefined **)((undefined *)&DAT_0000_d27e + in_BX) = (undefined *)&DAT_0000_6400;
  }
  return in_AX;
}


