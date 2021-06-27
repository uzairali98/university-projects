using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

using Photon.Pun;
using Photon.Realtime;


public class Launcher : MonoBehaviourPunCallbacks
{
    [SerializeField]
    private byte maxPlayersPerRoom = 2;
	
    bool isConnecting;
    string gameVersion = "1";
	private bool is_saved;
	private int PlayerXp=-1;
    [Space(10)]
    [Header("Custom Variables")]
    public InputField playerNameField;
    public InputField roomNameField;

    [Space(5)]
    public Text playerStatus;
    public Text connectionStatus;
	public Text DataBaseStatus;

    [Space(5)]
    public GameObject buttonLoadArena;
    public GameObject buttonJoinRoom;
	public GameObject EnterButton;

    string playerName = "";
    string roomName = "";

    // Start Method
	void Start() 
	{
		PlayerPrefs.DeleteAll(); 
		Debug.Log("Connecting to Photon Network");
		buttonLoadArena.SetActive(false);
		buttonJoinRoom.SetActive(false);
		is_saved = false;
		ConnectToPhoton();
	}

    void Awake()
	{
		PhotonNetwork.AutomaticallySyncScene = true;
	}
	public void Enter()
    {
		playerName = playerNameField.text;
		roomName = roomNameField.text;
		Debug.Log("player name " + playerName);
		Debug.Log("room name " + roomName);
		EnterButton.SetActive(false);
		//DATABASE ACCESSING
		StartCoroutine(DBaccess());
		is_saved = true;
	}

	IEnumerator DBaccess()
    {
		WWWForm form = new WWWForm();
		form.AddField("name",playerNameField.text);
		WWW www = new WWW("http://localhost/DataBaseProject/Register_Login.php", form);
		yield return www;
		PlayerXp = int.Parse(www.text);
		if (PlayerXp == 0)
			DataBaseStatus.text = "player NOT found..Adding player to the database";
		else
			DataBaseStatus.text = "found player with xp " +PlayerXp.ToString();

		VarHolderscript.Instance.Player_XP = PlayerXp;
		VarHolderscript.Instance.Player_Name = playerNameField.text;
    }
	void ConnectToPhoton()
	{
		connectionStatus.text = "Connecting...";
		PhotonNetwork.GameVersion = gameVersion; //1
		PhotonNetwork.ConnectUsingSettings(); //2
	}
     
	
	public void JoinRoom()
	{
		if (PhotonNetwork.IsConnected)
		{
			PhotonNetwork.LocalPlayer.NickName = playerName; //1
			Debug.Log("PhotonNetwork.IsConnected! | Trying to Create/Join Room " + 
				roomNameField.text);
			RoomOptions roomOptions = new RoomOptions(); //2
			TypedLobby typedLobby = new TypedLobby(roomName, LobbyType.Default); //3
			PhotonNetwork.JoinOrCreateRoom(roomName, roomOptions, typedLobby); //4
			buttonJoinRoom.SetActive(false);
		}
	}
	public void LoadArena()
	{
		// 5
		if (PhotonNetwork.CurrentRoom.PlayerCount > 1)
		{
			PhotonNetwork.LoadLevel(1);
		}
		else
		{
			playerStatus.text = "Minimum 2 Players required to Load Arena!";
		}
	}
	// Photon Methods
	public override void OnConnected()
	{
		// 1
		base.OnConnected();
		// 2
		connectionStatus.text = "Connected to Photon!";
		connectionStatus.color = Color.green;
		buttonLoadArena.SetActive(false);
		buttonJoinRoom.SetActive(true);
	}

	public override void OnDisconnected(DisconnectCause cause)
	{
		// 3
		isConnecting = false;
		Debug.LogError("Disconnected. Please check your Internet connection.");
	}

	public override void OnJoinedRoom()
	{
		// 4
		if (PhotonNetwork.IsMasterClient)
		{
			buttonLoadArena.SetActive(true);
			buttonJoinRoom.SetActive(false);
			playerStatus.text = "You are Lobby Leader";
		}
		else
		{
			playerStatus.text = "Connected to Lobby";
		}
	}


}

