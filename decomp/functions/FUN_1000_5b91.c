/* 1000:5b91 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_5b91(void)

{
  uint *puVar1;
  int iVar2;
  undefined2 uVar3;
  uint in_DX;
  uint *unaff_SI;
  undefined2 unaff_DS;
  undefined2 in_FS;
  undefined2 in_stack_00000000;
  
  *(char *)unaff_SI = (char)*unaff_SI;
  if (*(int *)0xc27e != -1) {
    in_DX = 0;
  }
  puVar1 = unaff_SI;
  iVar2 = (in_DX & 3) - (*puVar1 & 3);
  *puVar1 = *puVar1 + (uint)(0 < iVar2) * iVar2;
  uVar3 = CONCAT11((char)((uint)in_stack_00000000 >> 8),(char)in_stack_00000000 * '\x02');
  *(undefined2 *)(in_DX + 0xc016) = uVar3;
  LOCK();
  *(undefined2 *)(in_DX + 0xc27e) = uVar3;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


