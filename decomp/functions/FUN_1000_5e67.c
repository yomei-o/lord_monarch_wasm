/* 1000:5e67 */

undefined4 FUN_1000_5e67(void)

{
  undefined1 uVar1;
  undefined2 in_AX;
  char extraout_DL;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  char cVar2;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  FUN_1000_5e83();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) - extraout_DL;
  cVar2 = '\0';
  FUN_1000_7a82(0x55);
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + (char)extraout_DX + cVar2;
  uVar1 = in(extraout_DX);
  return CONCAT22(CONCAT11((char)((uint)in_AX >> 8),uVar1),
                  (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200
                  | (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40
                  | (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
}


