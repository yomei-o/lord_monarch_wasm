/* 1000:1388 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011539) overlaps instruction at (ram,0x00011538)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x000115ef) */
/* WARNING: Removing unreachable block (ram,0x00011641) */
/* WARNING: Removing unreachable block (ram,0x000115f1) */
/* WARNING: Removing unreachable block (ram,0x000113ba) */
/* WARNING: Removing unreachable block (ram,0x000113ab) */
/* WARNING: Removing unreachable block (ram,0x000113b6) */
/* WARNING: Removing unreachable block (ram,0x000113bc) */
/* WARNING: Removing unreachable block (ram,0x000113d2) */
/* WARNING: Removing unreachable block (ram,0x0001142d) */
/* WARNING: Removing unreachable block (ram,0x000113de) */
/* WARNING: Removing unreachable block (ram,0x000113ec) */
/* WARNING: Removing unreachable block (ram,0x000113e8) */
/* WARNING: Removing unreachable block (ram,0x000113f0) */
/* WARNING: Removing unreachable block (ram,0x000113f2) */
/* WARNING: Removing unreachable block (ram,0x000113fc) */
/* WARNING: Removing unreachable block (ram,0x000114d4) */
/* WARNING: Removing unreachable block (ram,0x00011538) */
/* WARNING: Removing unreachable block (ram,0x0001154a) */
/* WARNING: Removing unreachable block (ram,0x00011559) */
/* WARNING: Removing unreachable block (ram,0x0001156e) */
/* WARNING: Removing unreachable block (ram,0x0001157f) */
/* WARNING: Removing unreachable block (ram,0x00011599) */
/* WARNING: Removing unreachable block (ram,0x0001158d) */
/* WARNING: Removing unreachable block (ram,0x0001159f) */
/* WARNING: Removing unreachable block (ram,0x000115a6) */
/* WARNING: Removing unreachable block (ram,0x000115a9) */
/* WARNING: Removing unreachable block (ram,0x000115ab) */
/* WARNING: Removing unreachable block (ram,0x000115ad) */
/* WARNING: Removing unreachable block (ram,0x00011686) */
/* WARNING: Removing unreachable block (ram,0x00011692) */
/* WARNING: Removing unreachable block (ram,0x00011697) */
/* WARNING: Removing unreachable block (ram,0x0001169e) */
/* WARNING: Removing unreachable block (ram,0x00011690) */
/* WARNING: Removing unreachable block (ram,0x0001167a) */
/* WARNING: Removing unreachable block (ram,0x000115b0) */
/* WARNING: Removing unreachable block (ram,0x000115e1) */
/* WARNING: Removing unreachable block (ram,0x000115e6) */
/* WARNING: Removing unreachable block (ram,0x000115d6) */
/* WARNING: Removing unreachable block (ram,0x00011580) */
/* WARNING: Removing unreachable block (ram,0x00011602) */
/* WARNING: Removing unreachable block (ram,0x0001150e) */
/* WARNING: Removing unreachable block (ram,0x00011525) */
/* WARNING: Removing unreachable block (ram,0x00011528) */
/* WARNING: Removing unreachable block (ram,0x00011604) */
/* WARNING: Removing unreachable block (ram,0x000115b7) */
/* WARNING: Removing unreachable block (ram,0x000115bc) */
/* WARNING: Removing unreachable block (ram,0x0001161f) */
/* WARNING: Removing unreachable block (ram,0x000115c5) */
/* WARNING: Removing unreachable block (ram,0x00011444) */
/* WARNING: Removing unreachable block (ram,0x00011460) */
/* WARNING: Removing unreachable block (ram,0x00011475) */
/* WARNING: Removing unreachable block (ram,0x00011496) */
/* WARNING: Removing unreachable block (ram,0x000170ef) */
/* WARNING: Removing unreachable block (ram,0x000170f2) */
/* WARNING: Removing unreachable block (ram,0x00011481) */
/* WARNING: Removing unreachable block (ram,0x000113bb) */

void FUN_1000_1388(void)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  undefined2 in_AX;
  uint in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + (char)in_BX + in_CF;
  if ((*(byte *)0x3b19 & 0x80) == 0) {
    puVar2 = (uint *)(in_BX + unaff_SI);
    iVar3 = (in_DX & 3) - (*puVar2 & 3);
    *puVar2 = *puVar2 + (uint)(0 < iVar3) * iVar3;
  }
  else {
    pcVar1 = (char *)(unaff_BP + unaff_DI + 0x10);
    *pcVar1 = *pcVar1 - (char)((uint)in_AX >> 8);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


