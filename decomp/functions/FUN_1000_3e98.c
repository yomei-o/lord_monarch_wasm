/* 1000:3e98 */

undefined2 __cdecl16near FUN_1000_3e98(void)

{
  uint *puVar1;
  uint uVar2;
  byte bVar3;
  undefined2 in_AX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  
  bVar3 = ((undefined *)&DAT_0000_d27e)[unaff_DI] - 8;
  if (((7 < (byte)((undefined *)&DAT_0000_d27e)[unaff_DI]) && (bVar3 < 4)) &&
     (bVar3 == *(byte *)(unaff_SI + 0xc))) {
    bVar3 = ((undefined *)&DAT_0000_d27f)[unaff_DI];
    puVar1 = (uint *)(unaff_SI + 6);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + (uint)bVar3;
    if (CARRY2(uVar2,(uint)bVar3)) {
      *(undefined2 *)(unaff_SI + 6) = 0xffff;
    }
    *(undefined **)((undefined *)&DAT_0000_d27e + unaff_DI) = (undefined *)&DAT_0000_6400;
    return in_AX;
  }
  return in_AX;
}


