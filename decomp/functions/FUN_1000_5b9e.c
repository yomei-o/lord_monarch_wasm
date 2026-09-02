/* 1000:5b9e */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_5b9e(void)

{
  uint *puVar1;
  int iVar2;
  undefined2 uVar3;
  uint in_BX;
  int unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar1 = (uint *)(in_BX + unaff_SI);
  iVar2 = (in_BX & 3) - (*puVar1 & 3);
  *puVar1 = *puVar1 + (uint)(0 < iVar2) * iVar2;
  uVar3 = CONCAT11((char)((uint)unaff_ES >> 8),(char)unaff_ES * '\x02');
  *(undefined2 *)(in_BX + 0xc016) = uVar3;
  LOCK();
  *(undefined2 *)(in_BX + 0xc27e) = uVar3;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


