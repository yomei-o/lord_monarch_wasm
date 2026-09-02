/* 1000:3cd6 */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */
/* WARNING: Removing unreachable block (ram,0x00013d25) */
/* WARNING: Removing unreachable block (ram,0x0001847f) */
/* WARNING: Removing unreachable block (ram,0x000184cc) */
/* WARNING: Removing unreachable block (ram,0x0001848d) */
/* WARNING: Removing unreachable block (ram,0x00018492) */
/* WARNING: Removing unreachable block (ram,0x00018496) */
/* WARNING: Removing unreachable block (ram,0x000184d5) */
/* WARNING: Removing unreachable block (ram,0x000184a3) */
/* WARNING: Removing unreachable block (ram,0x000184d0) */
/* WARNING: Removing unreachable block (ram,0x000184b6) */
/* WARNING: Removing unreachable block (ram,0x000184d4) */
/* WARNING: Removing unreachable block (ram,0x000184d9) */
/* WARNING: Removing unreachable block (ram,0x000184e2) */
/* WARNING: Removing unreachable block (ram,0x000184fa) */
/* WARNING: Removing unreachable block (ram,0x000184de) */
/* WARNING: Removing unreachable block (ram,0x000184e9) */
/* WARNING: Removing unreachable block (ram,0x000184fd) */

void FUN_1000_3cd6(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  byte in_CL;
  int iVar3;
  int in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  
  *(undefined2 *)(unaff_SI + 0x33) = in_FS;
  pbVar1 = (byte *)(unaff_BP + -0x742b);
  *pbVar1 = *pbVar1 << (in_CL & 7) | *pbVar1 >> 8 - (in_CL & 7);
  iVar3 = in_BX;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *puVar2 = 0xffff;
    }
    unaff_DI = unaff_DI + (0x18 - in_BX);
    in_DX = in_DX + -1;
    iVar3 = in_BX;
  } while (in_DX != 0);
  return;
}


