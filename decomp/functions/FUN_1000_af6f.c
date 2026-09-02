/* 1000:af6f */

char __cdecl16near FUN_1000_af6f(void)

{
  char cVar1;
  char in_AL;
  char in_AH;
  char extraout_AH;
  char extraout_AH_00;
  char extraout_AH_01;
  undefined2 uVar2;
  uint unaff_DI;
  undefined2 unaff_DS;
  bool bVar3;
  
  uVar2 = 0x808;
  if (((byte)((undefined *)&DAT_0000_d21e)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d1be)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) && ((byte)(cVar1 - 8U) < 8)))))) {
    bVar3 = 0xbf < unaff_DI;
    in_AL = FUN_1000_ae9e();
    in_AH = extraout_AH;
    if (!bVar3) {
      return '\0';
    }
  }
  if (((byte)((undefined *)&DAT_0000_d2de)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d33e)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) &&
       ((byte)(cVar1 - (char)((uint)uVar2 >> 8)) < (byte)uVar2)))))) {
    bVar3 = 0xff3f < unaff_DI;
    in_AL = FUN_1000_ae9e();
    in_AH = extraout_AH_00;
    if (!bVar3) {
      return '\x04';
    }
  }
  if (((byte)((undefined *)&DAT_0000_d27c)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d27a)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) &&
       ((byte)(cVar1 - (char)((uint)uVar2 >> 8)) < (byte)uVar2)))))) {
    bVar3 = 3 < unaff_DI;
    in_AL = FUN_1000_ae9e();
    in_AH = extraout_AH_01;
    if (!bVar3) {
      return '\x02';
    }
  }
  if (((byte)((undefined *)&DAT_0000_d280)[unaff_DI] < 0x30) &&
     ((cVar1 = ((undefined *)&DAT_0000_d282)[unaff_DI], cVar1 == '\0' ||
      (((cVar1 != in_AL && (cVar1 != in_AH)) &&
       ((byte)(cVar1 - (char)((uint)uVar2 >> 8)) < (byte)uVar2)))))) {
    bVar3 = 0xfffb < unaff_DI;
    in_AL = FUN_1000_ae9e();
    if (!bVar3) {
      return '\x06';
    }
  }
  return in_AL;
}


