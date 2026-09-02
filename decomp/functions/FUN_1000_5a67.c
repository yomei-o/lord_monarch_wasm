/* 1000:5a67 */

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

uint FUN_1000_5a67(void)

{
  char cVar1;
  byte bVar2;
  byte in_CL;
  int iVar3;
  undefined2 extraout_DX;
  undefined2 *puVar4;
  undefined1 *puVar5;
  uint *puVar6;
  undefined2 *unaff_BP;
  int *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  longdouble in_ST0;
  
  *(char *)((int)unaff_BP + unaff_DI) = *(char *)((int)unaff_BP + unaff_DI) << (in_CL & 0x1f);
  *unaff_BP = 0x5a6f;
  FUN_1000_5abc();
  puVar4 = unaff_BP + -1;
  unaff_BP[-1] = 0x5a89;
  FUN_1000_5abc();
  puVar5 = (undefined1 *)((int)puVar4 + -2);
  *(undefined2 *)((int)puVar4 + -2) = 0x5a91;
  cVar1 = FUN_1000_5abc();
  iVar3 = CONCAT11(cVar1 << 3,in_CL);
  puVar6 = (uint *)(puVar5 + -2);
  *(undefined2 *)(puVar5 + -2) = 0x5a9f;
  bVar2 = FUN_1000_5abc();
  *unaff_SI = (int)ROUND(in_ST0);
  if (iVar3 != 0) {
    *puVar6 = 0x5ab0;
    FUN_1000_5ab9();
    return *puVar6;
  }
  puVar6[-1] = extraout_DX;
  return (uint)(byte)((bVar2 >> 4) * '\n' + (bVar2 & 0xf));
}


