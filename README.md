# AssetDrivenAIAgentTeams
License: CC BY-NC <br/>
Author: Dominik Rudnik (Qikcik)

## Video Demo
[![Video on Youtube](https://img.youtube.com/vi/VAKQ07_wojU/0.jpg)](https://www.youtube.com/watch?v=VAKQ07_wojU)

## Purpose of this plugin
It was created to allow designer using only blueprint to define ai agent character teams, and relations between them.

## How to use them
### Adding Teams
After enabling plugin inside project you will can create new AgentTeam from context menu in content browser
<br/>![](Pictures/3.png)<br/>

### Editing Team
You can edit it single via data asset details panel
<br/>![](Pictures/4.png)<br/>
**Default Attitude to strangers** Is attitude to all teams that arent specified in Attitude Towards.

### Editing Teams by edit via matrix
Or you can use EditViaMatrix from Scripted Actions
<br/>![](Pictures/5.png)<br/>
![](Pictures/6.png)<br/>
**At the bottom control buttons:**
- Add, open dialog for creating new Agent Teams
- Save All, save all actually editing Agent Teams
- Get All From Asset Registry, show in matrix all Agent Teams that are in main Content folder
- Get Selected In Content Browser, show in matrix all Agent Teams that are actually selected in content browser

**Columns represents Each Agent Teams**
- you can change Agent Teams name
- specifies Default Attitude to strangers.
- Edit button, open current Agent Teams in data asset details panel
- Each others Columns represents Attitude toward specifics Teams 

## How to assign Team to Character
first of all character need to inherit from **TeamedCharacter**
*(if you have yours c++ Character base class, you can copy Team implementation from **TeamedCharacter**)*
<br/>![](Pictures/1.png)<br/>
Now you can specify character team via Team variable inside TeamedCharacter category.
<br/>![](Pictures/2.png)<br/>


## Extensing Example
### Video
[![Video on Youtube](https://img.youtube.com/vi/oMqZNxIG94Y/0.jpg)](https://www.youtube.com/watch?v=oMqZNxIG94Y)

### Short Description
To Extend Agent Team with your game specifc data. You can create new Class inherited from AgentTeamExtendInfo, both inside c++ and blueprint.
<br/>
You can specify it inside each AgentTeam, by adding to Extend Infos set.
<br/><br/>
- **If you duplicate inherited Extend Info of the same class, during validation you will get a warning.** at runtime it will returned first object in set, inherited from class.
- **If you will try to access inherited Extend Info of class that aren`t specified inside agent Team it will be automatically created.**

## That's all!