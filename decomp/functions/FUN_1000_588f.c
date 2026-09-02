/* 1000:588f */

ulong FUN_1000_588f(void)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  undefined2 in_AX;
  int in_CX;
  int iVar4;
  int in_DX;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  char *pcVar5;
  int unaff_DI;
  char *pcVar6;
  char *pcVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  bool bVar8;
  
  out(*unaff_SI,in_DX);
  *(byte *)(unaff_DI + 0x57) = *(byte *)(unaff_DI + 0x57) | (byte)(in_DX + 1);
  bVar3 = 9 < ((byte)in_AX & 0xf) | in_AF;
  *(byte *)(unaff_BP + -2) = *(byte *)(unaff_BP + -2) | (byte)((uint)(in_DX + 1) >> 8);
  pcVar7 = (char *)*(undefined2 *)0x2674;
  do {
    if (*pcVar7 == '\0') break;
    pcVar5 = (char *)*(undefined2 *)(unaff_BP + -2);
    iVar4 = 0xb;
    bVar8 = false;
    pcVar6 = pcVar7;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar2 = pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
      bVar8 = *pcVar1 == *pcVar2;
    } while (bVar8);
    if (bVar8) {
      *(int *)(pcVar5 + in_BX + 0x2627) = in_BX;
      goto code_r0x000158c9;
    }
    pcVar7 = pcVar7 + 0x20;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  *(undefined1 *)0x3e92 = 0x80;
code_r0x000158c9:
  return CONCAT22(in_DX + 2,CONCAT11((char)((uint)in_AX >> 8) - bVar3,(byte)in_AX + bVar3 * -6)) &
         0xffffff0f;
}


