// SPDX-License-Identifier: MIT
pragma solidity ^0.8.5;

contract LocationTracking{
    mapping(string => usersdata) public credentials; //user , pass
    string name;
    string password;

    constructor() 
    {
        credentials["Duser1"].pass="Duser1123";
        credentials["Duser1"].isValue=true;
        credentials["Duser1"].isloggedin=false;
        credentials["Duser1"].longitude=0;
        credentials["Duser1"].latitude=0;

        credentials["Duser2"].pass="Duser2123";
        credentials["Duser2"].isValue=true; 
        credentials["Duser2"].isloggedin=false;
        credentials["Duser2"].longitude=0;
        credentials["Duser2"].latitude=0;     
    }

    function rand()
        public
        view
        returns(uint256)
    {
        uint256 seed = uint256(keccak256(abi.encodePacked(
            block.timestamp + block.difficulty +
            ((uint256(keccak256(abi.encodePacked(block.coinbase)))) / (block.timestamp)) +
            block.gaslimit + 
            ((uint256(keccak256(abi.encodePacked(msg.sender)))) / (block.timestamp)) +
            block.number
        )));

        return (seed - ((seed / 1000) * 1000));
    }

    function login() public returns (string memory)
    {
            
            if(credentials[name].isValue == true && compareStrings(credentials[name].pass,password))
            {
                if(credentials[name].isloggedin==true)
                {
                    return "already logged-in";
                }
                credentials[name].isloggedin=true;
                return ("logged in sucessfully");
            }
            return("credentials not correct");
    }

    function location_ping() public //a kind of mimicing locations of users  
    {
        if(credentials[name].isloggedin==false)
        return;
        credentials[name].longitude = rand();
        credentials[name].latitude = rand();
    }

    function get_longi() public view returns(uint256)
    {
        if(credentials[name].isloggedin==false)
        return 0;
        return(credentials[name].longitude);
    }

    function get_lati() public view returns(uint256)
    {
        if(credentials[name].isloggedin==false)
        return 0;
        return(credentials[name].latitude);
    }


    function set_name(string memory nam) public
    {
        name = nam;
    }

    function set_password(string memory pass) public
    {
        password = pass;
    }

    function logout() public returns (string memory)
    {
            if(credentials[name].isValue == true && compareStrings(credentials[name].pass,password))
            {
                if(credentials[name].isloggedin==false)
                {
                    return "already logged-out";
                }
                credentials[name].isloggedin=false;
                return ("Logged out sucessfully");
            }
            return("credentials not logged-in");
    }

    function compareStrings(string memory a, string memory b) private view returns(bool) 
    {
    return (keccak256(abi.encodePacked((a))) == keccak256(abi.encodePacked((b))));
    }
    
}

contract Noti//oracle can only execute notfication contract
{
    //NOTES
    // clustering requires looping like in k means and other clustering algos 
    // and loops are not allowed in SC so clustering is not possible
    mapping(string => usersdata) public credentials; //user , pass
    constructor() 
    {
        credentials["Duser1"].pass="Duser1123";
        credentials["Duser1"].isValue=true;
        credentials["Duser1"].isloggedin=false;
        credentials["Duser1"].longitude=0;
        credentials["Duser1"].latitude=0;

        credentials["Duser2"].pass="Duser2123";
        credentials["Duser2"].isValue=true; 
        credentials["Duser2"].isloggedin=false;
        credentials["Duser2"].longitude=0;
        credentials["Duser2"].latitude=0;     
    }

    function red_update(string memory name) public
    { 
        credentials[name].Red=true;
    }
    
    function yellow_update(string memory name) public
    {
        credentials[name].Yellow=true;
    }
    
    function gree_update(string memory name) public
    {
        credentials[name].Green=true;
    }

    function broadcast_infected(string memory name) public returns (string memory)
    {
        //broadcasts the reds and Dapp users will get notified
        if(credentials[name].Red)
        {
        return(name);
        }
    }
}

struct usersdata 
{
    uint256 longitude;
    uint256 latitude;
     string pass;
     bool isValue;
     bool isloggedin;
     bool Red;
     bool Yellow;
     bool Green;
}

struct oracledata 
{
     string pass;
     bool isValue;
     bool isloggedin;
}

contract Oracles//ye noti contract ko chalaye gaa after logged in
{
    mapping(string => oracledata) private credentials; //user , pass
    string name;
    string password;
    constructor() 
    {
        credentials["ali"].pass="ali123";
        credentials["ali"].isValue=true;
        credentials["ali"].isloggedin=false;
        
        credentials["kashif"].pass="kashif123";
        credentials["kashif"].isValue=true; 
        credentials["kashif"].isloggedin=false;     
    }

    function set_name(string memory nam) public
    {
        name = nam;
    }

    function set_password(string memory pass) public
    {
        password = pass;
    }

    function login() public returns (string memory)
    {
            
            if(credentials[name].isValue == true && compareStrings(credentials[name].pass,password))
            {
                if(credentials[name].isloggedin==true)
                {
                    return "already logged-in";
                }
                credentials[name].isloggedin=true;
                return ("logged in sucessfully");
            }
            return("credentials not correct");
    }

    function logout() public returns (string memory)
    {
            if(credentials[name].isValue == true && compareStrings(credentials[name].pass,password))
            {
                if(credentials[name].isloggedin==false)
                {
                    return "already logged-out";
                }
                credentials[name].isloggedin=false;
                return ("Logged out sucessfully");
            }
            return("credentials not logged-in");
    }

    function compareStrings(string memory a, string memory b) private view returns(bool) 
    {
    return (keccak256(abi.encodePacked((a))) == keccak256(abi.encodePacked((b))));
    }

}