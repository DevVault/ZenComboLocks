modded class MissionServer
{
	// Called when server initializes
	override void OnInit()
	{
		super.OnInit();
		Print("[ZenComboLocks] OnInit");

		// Load config
		GetZenComboLocksConfig();
	}

	// Called when a player connects to the server
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) 
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity) 
			return;

		// Delay sending of client config to avoid spamming new client login along with data from other mods
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendComboLockConfig, 5000, false, player);
	}

	// Send combo lock config to player from server
	void SendComboLockConfig(PlayerBase player)
	{
		if (!player || !player.GetIdentity())
			return;

		// Send client config
		Param2<ZenComboLocksClientConfig, bool> configParams = new Param2<ZenComboLocksClientConfig, bool>(
			GetZenComboLocksConfig().ClientSyncConfig,
			GetZenComboLocksConfig().IsAdminZCBL(player.GetIdentity().GetPlainId()));
		GetRPCManager().SendRPC("RPC_ZCL", "RPC_ReceiveZenComboLocksConfigOnClient", configParams, true, player.GetIdentity());
	}
};