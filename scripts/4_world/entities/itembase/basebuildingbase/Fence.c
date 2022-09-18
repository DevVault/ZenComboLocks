modded class Fence
{
	override void SetActions()
	{
		super.SetActions();

		// Allow use of these actions on any area of fence if enabled in server config
		AddAction(Zen_ActionNextCombinationLockDialOnFence);
		AddAction(Zen_ActionOpenComboLockFence);
		AddAction(Zen_ActionOpenComboLockInstantFence);
		AddAction(Zen_ActionDialCombinationLockOnFence);
		AddAction(Zen_ActionManageCombinationLockOnFence);
		AddAction(Zen_ActionAdminCombinationLockOnFence);
	}

	// Lock the combo lock when fence is shut (if it's not locked already)
	override void CloseFence()
	{
		super.CloseFence();

		if (this.GetCombinationLock() && !this.GetCombinationLock().IsLocked())
		{
			this.GetCombinationLock().LockServer(this);
		}
	}
};