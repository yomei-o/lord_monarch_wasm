/* 1000:1460 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_1460(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte in_AL;
  byte bVar3;
  byte bVar4;
  undefined1 uVar5;
  int in_CX;
  char extraout_DH;
  undefined2 extraout_DX;
  int in_BX;
  int iVar6;
  int unaff_BP;
  uint uVar7;
  byte *unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte in_AF;
  undefined8 in_MM0;
  undefined2 in_ST0h;
  undefined1 in_stack_00000000;
  undefined1 in_stack_00000001;
  undefined1 uStack0003;
  undefined2 uStack0005;
  
  *unaff_SI = (*unaff_SI - in_AL) - in_CF;
  pbVar2 = (byte *)CONCAT11(in_stack_00000001,in_stack_00000000);
  *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + (char)in_CX + (in_AL < *pbVar2);
                    /* WARNING: Call to offcut address within same function */
  func_0x000170e1();
  uStack0003 = 0x14;
  bVar3 = FUN_1000_0cfe();
  *pbVar2 = *unaff_SI;
  unaff_SI[in_BX + -1] = unaff_SI[in_BX + -1] & (byte)in_CX;
  uVar7 = unaff_BP + in_CX;
  bVar4 = bVar3 + (9 < (bVar3 & 0xf) | in_AF) * '\x06' + (0x99 < bVar3) * '`';
  iVar6 = CONCAT11(((char)((uint)in_BX >> 8) - extraout_DH) -
                   (0x8a < bVar4 || CARRY1(bVar4 + 0x75,0x99 < bVar3)),(char)in_BX);
  uStack0003 = (undefined1)unaff_SS;
  if (&stack0x0000 != (undefined1 *)0xfffb) {
    *(long *)(iVar6 + -0x75) = (long)ROUND((longdouble)CONCAT28(in_ST0h,in_MM0));
    unaff_SI[-0x2778] = unaff_SI[-0x2778] + 1;
    bVar3 = *(byte *)(iVar6 + -0x318c);
    out(0x7e,bVar3);
    pshufw(in_MM0,*(undefined8 *)(unaff_SI + (uVar7 - 2)),0x97);
    if (bVar3 == unaff_SI[uVar7 - 2]) {
      unaff_SI[uVar7 - 2] = bVar3;
    }
    pbVar2[0x4b] = 0x72;
    pbVar2[-5] = 0x72;
    puVar1 = (uint *)(pbVar2 + -6);
    iVar6 = (uVar7 & 3) - (*puVar1 & 3);
    *puVar1 = *puVar1 + (uint)(0 < iVar6) * iVar6;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x00010d23();
                    /* WARNING: Call to offcut address within same function */
  uStack0005 = 0x148c;
  uVar5 = func_0x000170dc();
  out(extraout_DX,uVar5);
  return;
}


