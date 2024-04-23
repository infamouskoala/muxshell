# SAMPLE REVERSE SHELL

- Before anything, this project is for educational and testing purposes only. While programming this, I kept in mind to not be blatant or cause any real harm to the victims with this. Use this for educational purposes only.

- This repo is supposed to be a repo where i upload malware or anything that i make for testing purposes. The one in python file is optimised to run on linux and windows machines whereas the one coded in C is only built for Windows hosts.

- The clients will connect to the server as long as the server is active, Since there is no recursive search machenism, the client's wont keep looking if they dont find the server

- If you are unlucky enough to be hit with this, I have given some preventions below to safely remove the malware from your operating system.

# INSTALLATION

- Setup port forwarding on your router or rent out a VPS (recommended) since residential IP addresses are not ideal for this.

- Done so, clone the repo or download the files and build the payload.

### __BUILDING THE SERVER__
> Windows Machine

- Before running the following command, open the `server.py` and change the ip and address of the server.

```shell
py server.py
```
> Linux machine

- Before running the following command, open the `server.py` and change the ip and address of the server.

```shell
git clone <project_url>
cd muxshell
python server.py
```

### __BUILDING THE PAYLOAD__
> Target: Windows Machine

- Build anyone from C or Python one. Make sure to update the connection address before building it.

- For C:
```shell
gcc -o RENAMETHIS.exe muxshell/payload.c -lws2_32
```

- For Python:
```shell
pip install pyinstaller
pyinstaller --onefile muxshell/payload.py
```

# PULL REQUESTS

- I have my own plans with this repository, as I said this repo is for educational purposes which means I am learning and I will keep updating this repository and potentially make a counter and detection for this in the future too since thats what cybersecurity is about. For now, all the pull requests are welcome but won't nessassarily be merged since this is for my own learning and progress, I realise the community is 10x better than me but I am certainly trying!

# CHECKLIST
[ ] Implement Windows Defender bypass (Won't be public)
[ ] Implement a "launch on startup" logic via Windows API
[ ] Implement an Injection system (hopefully) to inject this into system files
[ ] Implement a vm detection
[ ] Implement some to send constant machine status to the backend servers
[ ] Implement self destruct machenism when being played with

# THANK YOU
- Thank you for checking out this repository! Every star encourages me on my journey. <3