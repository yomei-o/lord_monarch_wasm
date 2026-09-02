/* 1000:5ba1 */

/* WARNING: Control flow encountered bad instruction data */

ulong FUN_1000_5ba1(undefined2 param_1)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  undefined2 in_AX;
  undefined2 uVar4;
  char in_DL;
  uint in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool in_ZF;
  char in_SF;
  char in_OF;
  undefined2 in_stack_00000000;
  
  if (!in_ZF && in_OF == in_SF) {
    puVar2 = (uint *)(in_BX + unaff_SI);
    iVar3 = (in_BX & 3) - (*puVar2 & 3);
    *puVar2 = *puVar2 + (uint)(0 < iVar3) * iVar3;
    uVar4 = CONCAT11((char)((uint)in_stack_00000000 >> 8),(char)in_stack_00000000 * '\x02');
    *(undefined2 *)(in_BX + 0xc016) = uVar4;
    LOCK();
    *(undefined2 *)(in_BX + 0xc27e) = uVar4;
    UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar1 = (char *)(unaff_BP + unaff_SI + 0x53);
  *pcVar1 = (*pcVar1 - in_DL) - in_CF;
  out(0x8e9,0);
  out(0x8e1,0);
  return CONCAT22(param_1,in_AX) & 0xffffff00;
}


