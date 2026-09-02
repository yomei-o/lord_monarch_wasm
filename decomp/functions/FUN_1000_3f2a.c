/* 1000:3f2a */

undefined4 __cdecl16near FUN_1000_3f2a(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  
  if (3 < (byte)(((undefined *)&DAT_0000_d27e)[unaff_DI] - 1)) {
    return CONCAT22(in_DX,in_AX);
  }
  bVar3 = (byte)(*(uint *)(unaff_SI + 6) >> 1);
  if ((byte)(*(uint *)(unaff_SI + 6) >> 9) == 0) {
    pbVar1 = (undefined *)&DAT_0000_d27f + unaff_DI;
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 - bVar3;
    if (bVar3 <= bVar2 && *pbVar1 != 0) {
      return CONCAT22(in_DX,in_AX);
    }
  }
  *(undefined **)((undefined *)&DAT_0000_d27e + unaff_DI) = (undefined *)&DAT_0000_6400;
  FUN_1000_a7e9();
  return CONCAT22(in_DX,in_AX);
}


