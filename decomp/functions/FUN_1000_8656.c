/* 1000:8656 */

ulong FUN_1000_8656(void)

{
  uint uVar1;
  undefined2 in_AX;
  int in_CX;
  uint in_DX;
  uint *in_BX;
  uint unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  byte *pbVar2;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  do {
    if (!CARRY2(in_DX,*(uint *)(unaff_DI + 6))) {
      in_AX = thunk_FUN_1000_6571();
      uVar1 = *in_BX;
      if ((uVar1 != 1) && (uVar1 <= unaff_BP)) {
        unaff_SI = unaff_DI;
        unaff_BP = uVar1;
      }
    }
    do {
      pbVar2 = unaff_DI;
      unaff_DI = pbVar2 + 0x10;
      in_CX = in_CX + -1;
      if (in_CX == 0) {
        return CONCAT22(*(undefined2 *)(unaff_SI + 8),in_AX) | 0xc58b;
      }
    } while (((((*unaff_DI & (byte)((uint)in_AX >> 8)) != 0) || ((byte)in_AX != pbVar2[0x1c])) ||
             (in_BX = (uint *)(CONCAT11((char)((uint)in_BX >> 8),pbVar2[0x1a]) & 0xff0f),
             (char)in_BX != '\x02')) || (*(uint *)(pbVar2 + 0x16) < in_DX));
  } while( true );
}


