#ifdef BuildingFort_Mod_1A
modded class BF_DoorBarricade
{
	// Return whether or not this fence can be opened
	override bool CanOpenFence()
	{
		if (super.CanOpenFence())
			return true;

		if (HasHinges() && !IsOpened() && IsLocked())
		{
			if (GetGame().IsClient())
			{
				return this.GetCombinationLock() && this.GetCombinationLock().IsPermittedToOpen();
			}
		}

		return false;
	}

	// Set actions
	override void SetActions()
	{
		super.SetActions();
		AddAction(Zen_ActionNextCombinationLockDialOnFence);
		AddAction(Zen_ActionOpenComboLockFence);
		AddAction(Zen_ActionOpenComboLockInstantFence);
		AddAction(Zen_ActionDialCombinationLockOnFence);
		AddAction(Zen_ActionManageCombinationLockOnFence);
		AddAction(Zen_ActionAdminCombinationLockOnFence);
	}
};
#endif