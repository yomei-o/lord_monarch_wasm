/* 1000:3cc4 */

/* WARNING: Instruction at (ram,0x000184fa) overlaps instruction at (ram,0x000184f9)
    */
/* WARNING: Control flow encountered bad instruction data */
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

void FUN_1000_3cc4(void)

{
  byte *pbVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined2 *puVar4;
  byte bVar5;
  undefined2 in_AX;
  byte in_CL;
  undefined2 in_DX;
  int iVar6;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  int iVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  
  bVar5 = (byte)in_AX;
  if (*(int *)0x3288 == 0) {
    bVar5 = bVar5 + *(char *)(unaff_BP + (int)unaff_DI);
    pbVar1 = (byte *)(unaff_BP + (int)unaff_DI);
    *pbVar1 = *pbVar1 << 3 | *pbVar1 >> 5;
    iVar7 = CONCAT11((char)((uint)in_AX >> 8),bVar5) * 0x30 + in_BX;
    pbVar1 = (byte *)(unaff_BP + iVar7);
    *pbVar1 = *pbVar1 | bVar5;
    pbVar1 = (byte *)(unaff_BP + iVar7);
    *pbVar1 = *pbVar1 << (in_CL & 7) | *pbVar1 >> 8 - (in_CL & 7);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  LOCK();
  uVar2 = *(undefined1 *)(in_BX + unaff_SI);
  *(undefined1 *)(in_BX + unaff_SI) = (char)in_DX;
  iVar6 = CONCAT11((char)((uint)in_DX >> 8),uVar2);
  UNLOCK();
  pbVar1 = (byte *)(unaff_BP + (int)unaff_DI);
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 - bVar5;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + '>' + (bVar3 < bVar5);
  *(undefined2 *)(unaff_SI + 0x33) = in_FS;
  pbVar1 = (byte *)(unaff_BP + -0x742b);
  *pbVar1 = *pbVar1 << (in_CL & 7) | *pbVar1 >> 8 - (in_CL & 7);
  iVar7 = in_BX;
  do {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      puVar4 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *puVar4 = 0xffff;
    }
    unaff_DI = unaff_DI + (0x18 - in_BX);
    iVar6 = iVar6 + -1;
    iVar7 = in_BX;
  } while (iVar6 != 0);
  return;
}


