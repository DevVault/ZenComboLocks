#ifdef BuildingFort_Mod_1A
modded class ActionOpenBuildingCore
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			BF_DoorBarricade door = BF_DoorBarricade.Cast(target.GetObject());
			if (door)
			{
				if (door.GetCombinationLock() && door.GetCombinationLock().IsLockedOnGate())
				{
					return GetZenComboLocksConfig().ClientSyncConfig.InstantOpen;
				}
			}

			return true;
		}

		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		BuildingFortficationsCore bfc = BuildingFortficationsCore.Cast(action_data.m_Target.GetObject());
		if (bfc)
		{
			CombinationLock lock = ZenComboLocksHelper.GetCombinationLock(bfc);
			if (lock && lock.IsLockedOnGate() && lock.IsPermittedToOpen(action_data.m_Player))
			{
				bfc.OpenFence();
			}
		}
	}
};
#endif