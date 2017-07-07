#include "amiibolookup.h"

#include <string.h>
#include <map>


using namespace std;

static map<u16, const char*> idList = {
	{0x0000, "Mario (SSB)"},
	{0x0001, "Peach (SSB)"},
	{0x0002, "Yoshi (SSB)"},
	{0x0003, "Donkey Kong (SSB)"},
	{0x0004, "Link (SSB)"},
	{0x0005, "Fox (SSB)"},
	{0x0006, "Samus (SSB)"},
	{0x0007, "Wii Fit Trainer (SSB)"},
	{0x0008, "Villager (SSB)"},
	{0x0009, "Pikachu (SSB)"},
	{0x000A, "Kirby (SSB)"},
	{0x000B, "Marth (SSB)"},
	{0x000C, "Luigi (SSB)"},
	{0x000D, "Diddy Kong (SSB)"},
	{0x000E, "Zelda (SSB)"},
	{0x000F, "Little Mac (SSB)"},
	{0x0010, "Pit (SSB)"},
	{0x0011, "Lucario (SSB)"},
	{0x0012, "Captain Falcon (SSB)"},
	{0x0013, "Rosalina and Luma (SSB)"},
	{0x0014, "Bowser (SSB)"},
	{0x0015, "Bowser Jr. (SSB)"},
	{0x0016, "Toon Link (SSB)"},
	{0x0017, "Sheik (SSB)"},
	{0x0018, "Ike (SSB)"},
	{0x0019, "Dr. Mario (SSB)"},
	{0x001A, "Wario (SSB)"},
	{0x001B, "Ganondorf (SSB)"},
	{0x001C, "Falco (SSB)"},
	{0x001D, "Zero Suit Samus (SSB)"},
	{0x001E, "Olimar (SSB)"},
	{0x001F, "Palutena (SSB)"},
	{0x0020, "Dark Pit (SSB)"},
	{0x0021, "Mii Brawler (SSB)"},
	{0x0022, "Mii Swordfighter (SSB)"},
	{0x0023, "Mii Gunner (SSB)"},
	{0x0024, "Charizard (SSB)"},
	{0x0025, "Greninja (SSB)"},
	{0x0026, "Jigglypuff (SSB)"},
	{0x0027, "Meta Knight (SSB)"},
	{0x0028, "King Dedede (SSB)"},
	{0x0029, "Lucina (SSB)"},
	{0x002A, "Robin (SSB)"},
	{0x002B, "Shulk (SSB)"},
	{0x002C, "Ness (SSB)"},
	{0x002D, "Mr. Game & Watch (SSB)"},
	{0x002E, "R.O.B. (Famicom) (SSB)"},
	{0x002F, "Duck Hunt (SSB)"},
	{0x0030, "Sonic (SSB)"},
	{0x0031, "Mega Man (SSB)"},
	{0x0032, "Pac-Man (SSB)"},
	{0x0033, "R.O.B. (NES) (SSB)"},
	{0x0034, "Mario (SMB)"},
	{0x0035, "Luigi (SMB)"},
	{0x0036, "Peach (SMB)"},
	{0x0037, "Yoshi (SMB)"},
	{0x0038, "Toad (SMB)"},
	{0x0039, "Bowser (SMB)"},
	{0x003A, "Chibi-Robo (CHI)"},
	{0x003C, "Mario (Gold Edition) (SMB)"},
	{0x003D, "Mario (Silver Edition) (SMB)"},
	{0x003E, "Inkling Girl (SPL)"},
	{0x003F, "Inkling Boy (SPL)"},
	{0x0040, "Inkling Squid (SPL)"},
	{0x0041, "Green Yarn Yoshi (YWW)"},
	{0x0042, "Pink Yarn Yoshi (YWW)"},
	{0x0043, "Light-Blue Yarn Yoshi (YWW)"},
	{0x0044, "Isabelle (ACC1)"},
	{0x0045, "Tom Nook (ACC1)"},
	{0x0046, "DJ K.K. (ACC1)"},
	{0x0047, "Sable (ACC1)"},
	{0x0048, "Kappn (ACC1)"},
	{0x0049, "Resetti (ACC1)"},
	{0x004A, "Joan (ACC1)"},
	{0x004B, "Timmy (ACC1)"},
	{0x004C, "Digby (ACC1)"},
	{0x004D, "Pascal (ACC1)"},
	{0x004E, "Harriet (ACC1)"},
	{0x004F, "Redd (ACC1)"},
	{0x0050, "Saharah (ACC1)"},
	{0x0051, "Luna (ACC1)"},
	{0x0052, "Tortimer (ACC1)"},
	{0x0053, "Lyle (ACC1)"},
	{0x0054, "Lottie (ACC1)"},
	{0x0055, "Bob (ACC1)"},
	{0x0056, "Fauna (ACC1)"},
	{0x0057, "Curt (ACC1)"},
	{0x0058, "Portia (ACC1)"},
	{0x0059, "Leonardo (ACC1)"},
	{0x005A, "Cheri (ACC1)"},
	{0x005B, "Kyle (ACC1)"},
	{0x005C, "Al (ACC1)"},
	{0x005D, "RenÃ©e (ACC1)"},
	{0x005E, "Lopez (ACC1)"},
	{0x005F, "Jambette (ACC1)"},
	{0x0060, "Rasher (ACC1)"},
	{0x0061, "Tiffany (ACC1)"},
	{0x0062, "Sheldon (ACC1)"},
	{0x0063, "Bluebear (ACC1)"},
	{0x0064, "Bill (ACC1)"},
	{0x0065, "Kiki (ACC1)"},
	{0x0066, "Deli (ACC1)"},
	{0x0067, "Alli (ACC1)"},
	{0x0068, "Kabuki (ACC1)"},
	{0x0069, "Patty (ACC1)"},
	{0x006A, "Jitters (ACC1)"},
	{0x006B, "Gigi (ACC1)"},
	{0x006C, "Quillson (ACC1)"},
	{0x006D, "Marcie (ACC1)"},
	{0x006E, "Puck (ACC1)"},
	{0x006F, "Shari (ACC1)"},
	{0x0070, "Octavian (ACC1)"},
	{0x0071, "Winnie (ACC1)"},
	{0x0072, "Knox (ACC1)"},
	{0x0073, "Sterling (ACC1)"},
	{0x0074, "Bonbon (ACC1)"},
	{0x0075, "Punchy (ACC1)"},
	{0x0076, "Opal (ACC1)"},
	{0x0077, "Poppy (ACC1)"},
	{0x0078, "Limberg (ACC1)"},
	{0x0079, "Deena (ACC1)"},
	{0x007A, "Snake (ACC1)"},
	{0x007B, "Bangle (ACC1)"},
	{0x007C, "Phil (ACC1)"},
	{0x007D, "Monique (ACC1)"},
	{0x007E, "Nate (ACC1)"},
	{0x007F, "Samson (ACC1)"},
	{0x0080, "Tutu (ACC1)"},
	{0x0081, "T-Bone (ACC1)"},
	{0x0082, "Mint (ACC1)"},
	{0x0083, "Pudge (ACC1)"},
	{0x0084, "Midge (ACC1)"},
	{0x0085, "Gruff (ACC1)"},
	{0x0086, "Flurry (ACC1)"},
	{0x0087, "Clyde (ACC1)"},
	{0x0088, "Bella (ACC1)"},
	{0x0089, "Biff (ACC1)"},
	{0x008A, "Yuka (ACC1)"},
	{0x008B, "Lionel (ACC1)"},
	{0x008C, "Flo (ACC1)"},
	{0x008D, "Cobb (ACC1)"},
	{0x008E, "Amelia (ACC1)"},
	{0x008F, "Jeremiah (ACC1)"},
	{0x0090, "Cherry (ACC1)"},
	{0x0091, "Roscoe (ACC1)"},
	{0x0092, "Truffles (ACC1)"},
	{0x0093, "Eugene (ACC1)"},
	{0x0094, "Eunice (ACC1)"},
	{0x0095, "Goose (ACC1)"},
	{0x0096, "Annalisa (ACC1)"},
	{0x0097, "Benjamin (ACC1)"},
	{0x0098, "Pancetti (ACC1)"},
	{0x0099, "Chief (ACC1)"},
	{0x009A, "Bunnie (ACC1)"},
	{0x009B, "Clay (ACC1)"},
	{0x009C, "Diana (ACC1)"},
	{0x009D, "Axel (ACC1)"},
	{0x009E, "Muffy (ACC1)"},
	{0x009F, "Henry (ACC1)"},
	{0x00A0, "Bertha (ACC1)"},
	{0x00A1, "Cyrano (ACC1)"},
	{0x00A2, "Peanut (ACC1)"},
	{0x00A3, "Cole (ACC1)"},
	{0x00A4, "Willow (ACC1)"},
	{0x00A5, "Roald (ACC1)"},
	{0x00A6, "Molly (ACC1)"},
	{0x00A7, "Walker (ACC1)"},
	{0x00A8, "K.K. Slider (ACC2)"},
	{0x00A9, "Reese (ACC2)"},
	{0x00AA, "Kicks (ACC2)"},
	{0x00AB, "Labelle (ACC2)"},
	{0x00AC, "Copper (ACC2)"},
	{0x00AD, "Booker (ACC2)"},
	{0x00AE, "Katie (ACC2)"},
	{0x00AF, "Tommy (ACC2)"},
	{0x00B0, "Porter (ACC2)"},
	{0x00B1, "Leila (ACC2)"},
	{0x00B2, "Dr. Shrunk (ACC2)"},
	{0x00B3, "Don Resetti (ACC2)"},
	{0x00B4, "Isabelle (ACC2)"},
	{0x00B5, "Blanca (ACC2)"},
	{0x00B6, "Nat (ACC2)"},
	{0x00B7, "Chip (ACC2)"},
	{0x00B8, "Jack (ACC2)"},
	{0x00B9, "Poncho (ACC2)"},
	{0x00BA, "Felicity (ACC2)"},
	{0x00BB, "Ozzie (ACC2)"},
	{0x00BC, "Tia (ACC2)"},
	{0x00BD, "Lucha (ACC2)"},
	{0x00BE, "Fuchsia (ACC2)"},
	{0x00BF, "Harry (ACC2)"},
	{0x00C0, "Gwen (ACC2)"},
	{0x00C1, "Coach (ACC2)"},
	{0x00C2, "Kitt (ACC2)"},
	{0x00C3, "Tom (ACC2)"},
	{0x00C4, "Tipper (ACC2)"},
	{0x00C5, "Prince (ACC2)"},
	{0x00C6, "Pate (ACC2)"},
	{0x00C7, "Vladimir (ACC2)"},
	{0x00C8, "Savannah (ACC2)"},
	{0x00C9, "Kidd (ACC2)"},
	{0x00CA, "Phoebe (ACC2)"},
	{0x00CB, "Egbert (ACC2)"},
	{0x00CC, "Cookie (ACC2)"},
	{0x00CD, "Sly (ACC2)"},
	{0x00CE, "Blaire (ACC2)"},
	{0x00CF, "Avery (ACC2)"},
	{0x00D0, "Nana (ACC2)"},
	{0x00D1, "Peck (ACC2)"},
	{0x00D2, "Olivia (ACC2)"},
	{0x00D3, "Cesar (ACC2)"},
	{0x00D4, "Carmen (ACC2)"},
	{0x00D5, "Rodney (ACC2)"},
	{0x00D6, "Scoot (ACC2)"},
	{0x00D7, "Whitney (ACC2)"},
	{0x00D8, "Broccolo (ACC2)"},
	{0x00D9, "Coco (ACC2)"},
	{0x00DA, "Groucho (ACC2)"},
	{0x00DB, "Wendy (ACC2)"},
	{0x00DC, "Alfonso (ACC2)"},
	{0x00DD, "Rhonda (ACC2)"},
	{0x00DE, "Butch (ACC2)"},
	{0x00DF, "Gabi (ACC2)"},
	{0x00E0, "Moose (ACC2)"},
	{0x00E1, "Timbra (ACC2)"},
	{0x00E2, "Zell (ACC2)"},
	{0x00E3, "Pekoe (ACC2)"},
	{0x00E4, "Teddy (ACC2)"},
	{0x00E5, "Mathilda (ACC2)"},
	{0x00E6, "Ed (ACC2)"},
	{0x00E7, "Bianca (ACC2)"},
	{0x00E8, "Filbert (ACC2)"},
	{0x00E9, "Kitty (ACC2)"},
	{0x00EA, "Beau (ACC2)"},
	{0x00EB, "Nan (ACC2)"},
	{0x00EC, "Bud (ACC2)"},
	{0x00ED, "Ruby (ACC2)"},
	{0x00EE, "Benedict (ACC2)"},
	{0x00EF, "Agnes (ACC2)"},
	{0x00F0, "Julian (ACC2)"},
	{0x00F1, "Bettina (ACC2)"},
	{0x00F2, "Jay (ACC2)"},
	{0x00F3, "Sprinkle (ACC2)"},
	{0x00F4, "Flip (ACC2)"},
	{0x00F5, "Hugh (ACC2)"},
	{0x00F6, "Hopper (ACC2)"},
	{0x00F7, "Pecan (ACC2)"},
	{0x00F8, "Drake (ACC2)"},
	{0x00F9, "Alice (ACC2)"},
	{0x00FA, "Camofrog (ACC2)"},
	{0x00FB, "Anicotti (ACC2)"},
	{0x00FC, "Chops (ACC2)"},
	{0x00FD, "Charlise (ACC2)"},
	{0x00FE, "Vic (ACC2)"},
	{0x00FF, "Ankha (ACC2)"},
	{0x0100, "Drift (ACC2)"},
	{0x0101, "Vesta (ACC2)"},
	{0x0102, "Marcel (ACC2)"},
	{0x0103, "Pango (ACC2)"},
	{0x0104, "Keaton (ACC2)"},
	{0x0105, "Gladys (ACC2)"},
	{0x0106, "Hamphrey (ACC2)"},
	{0x0107, "Freya (ACC2)"},
	{0x0108, "Kid Cat (ACC2)"},
	{0x0109, "Agent S (ACC2)"},
	{0x010A, "Big Top (ACC2)"},
	{0x010B, "Rocket (ACC2)"},
	{0x010C, "Rover (ACC3)"},
	{0x010D, "Blathers (ACC3)"},
	{0x010E, "Tom Nook (ACC3)"},
	{0x010F, "Pelly (ACC3)"},
	{0x0110, "Phyllis (ACC3)"},
	{0x0111, "Pete (ACC3)"},
	{0x0112, "Mabel (ACC3)"},
	{0x0113, "Leif (ACC3)"},
	{0x0114, "Wendell (ACC3)"},
	{0x0115, "Cyrus (ACC3)"},
	{0x0116, "Grams (ACC3)"},
	{0x0117, "Timmy (ACC3)"},
	{0x0118, "Digby (ACC3)"},
	{0x0119, "Don Resetti (ACC3)"},
	{0x011A, "Isabelle (ACC3)"},
	{0x011B, "Franklin (ACC3)"},
	{0x011C, "Jingle (ACC3)"},
	{0x011D, "Lily (ACC3)"},
	{0x011E, "Anchovy (ACC3)"},
	{0x011F, "Tabby (ACC3)"},
	{0x0120, "Kody (ACC3)"},
	{0x0121, "Miranda (ACC3)"},
	{0x0122, "Del (ACC3)"},
	{0x0123, "Paula (ACC3)"},
	{0x0124, "Ken (ACC3)"},
	{0x0125, "Mitzi (ACC3)"},
	{0x0126, "Rodeo (ACC3)"},
	{0x0127, "Bubbles (ACC3)"},
	{0x0128, "Cousteau (ACC3)"},
	{0x0129, "Velma (ACC3)"},
	{0x012A, "Elvis (ACC3)"},
	{0x012B, "Canberra (ACC3)"},
	{0x012C, "Colton (ACC3)"},
	{0x012D, "Marina (ACC3)"},
	{0x012E, "Spork/Crackle (ACC3)"},
	{0x012F, "Freckles (ACC3)"},
	{0x0130, "Bam (ACC3)"},
	{0x0131, "Friga (ACC3)"},
	{0x0132, "Ricky (ACC3)"},
	{0x0133, "Deirdre (ACC3)"},
	{0x0134, "Hans (ACC3)"},
	{0x0135, "Chevre (ACC3)"},
	{0x0136, "Drago (ACC3)"},
	{0x0137, "Tangy (ACC3)"},
	{0x0138, "Mac (ACC3)"},
	{0x0139, "Eloise (ACC3)"},
	{0x013A, "Wart Jr. (ACC3)"},
	{0x013B, "Hazel (ACC3)"},
	{0x013C, "Beardo (ACC3)"},
	{0x013D, "Ava (ACC3)"},
	{0x013E, "Chester (ACC3)"},
	{0x013F, "Merry (ACC3)"},
	{0x0140, "Genji (ACC3)"},
	{0x0141, "Greta (ACC3)"},
	{0x0142, "Wolfgang (ACC3)"},
	{0x0143, "Diva (ACC3)"},
	{0x0144, "Klaus (ACC3)"},
	{0x0145, "Daisy (ACC3)"},
	{0x0146, "Stinky (ACC3)"},
	{0x0147, "Tammi (ACC3)"},
	{0x0148, "Tucker (ACC3)"},
	{0x0149, "Blanche (ACC3)"},
	{0x014A, "Gaston (ACC3)"},
	{0x014B, "Marshal (ACC3)"},
	{0x014C, "Gala (ACC3)"},
	{0x014D, "Joey (ACC3)"},
	{0x014E, "Pippy (ACC3)"},
	{0x014F, "Buck (ACC3)"},
	{0x0150, "Bree (ACC3)"},
	{0x0151, "Rooney (ACC3)"},
	{0x0152, "Curlos (ACC3)"},
	{0x0153, "Skye (ACC3)"},
	{0x0154, "Moe (ACC3)"},
	{0x0155, "Flora (ACC3)"},
	{0x0156, "Hamlet (ACC3)"},
	{0x0157, "Astrid (ACC3)"},
	{0x0158, "Monty (ACC3)"},
	{0x0159, "Dora (ACC3)"},
	{0x015A, "Biskit (ACC3)"},
	{0x015B, "Victoria (ACC3)"},
	{0x015C, "Lyman (ACC3)"},
	{0x015D, "Violet (ACC3)"},
	{0x015E, "Frank (ACC3)"},
	{0x015F, "Chadder (ACC3)"},
	{0x0160, "Merengue (ACC3)"},
	{0x0161, "Cube (ACC3)"},
	{0x0162, "Claudia (ACC3)"},
	{0x0163, "Curly (ACC3)"},
	{0x0164, "Boomer (ACC3)"},
	{0x0165, "Caroline (ACC3)"},
	{0x0166, "Sparro (ACC3)"},
	{0x0167, "Baabara (ACC3)"},
	{0x0168, "Rolf (ACC3)"},
	{0x0169, "Maple (ACC3)"},
	{0x016A, "Antonio (ACC3)"},
	{0x016B, "Soleil (ACC3)"},
	{0x016C, "Apollo (ACC3)"},
	{0x016D, "Derwin (ACC3)"},
	{0x016E, "Francine (ACC3)"},
	{0x016F, "Chrissy (ACC3)"},
	{0x0170, "Isabelle (ACC4)"},
	{0x0171, "Brewster (ACC4)"},
	{0x0172, "Katrina (ACC4)"},
	{0x0173, "Phineas (ACC4)"},
	{0x0174, "Celeste (ACC4)"},
	{0x0175, "Tommy (ACC4)"},
	{0x0176, "Gracie (ACC4)"},
	{0x0177, "Leilani (ACC4)"},
	{0x0178, "Resetti (ACC4)"},
	{0x0179, "Timmy (ACC4)"},
	{0x017A, "Lottie (ACC4)"},
	{0x017B, "Shrunk (ACC4)"},
	{0x017C, "Pave (ACC4)"},
	{0x017D, "Gulliver (ACC4)"},
	{0x017E, "Redd (ACC4)"},
	{0x017F, "Zipper (ACC4)"},
	{0x0180, "Goldie (ACC4)"},
	{0x0181, "Stitches (ACC4)"},
	{0x0182, "Pinky (ACC4)"},
	{0x0183, "Mott (ACC4)"},
	{0x0184, "Mallary (ACC4)"},
	{0x0185, "Rocco (ACC4)"},
	{0x0186, "Katt (ACC4)"},
	{0x0187, "Graham (ACC4)"},
	{0x0188, "Peaches (ACC4)"},
	{0x0189, "Dizzy (ACC4)"},
	{0x018A, "Penelope (ACC4)"},
	{0x018B, "Boone (ACC4)"},
	{0x018C, "Broffina (ACC4)"},
	{0x018D, "Croque (ACC4)"},
	{0x018E, "Pashmina (ACC4)"},
	{0x018F, "Shep (ACC4)"},
	{0x0190, "Lolly (ACC4)"},
	{0x0191, "Erik (ACC4)"},
	{0x0192, "Dotty (ACC4)"},
	{0x0193, "Pierce (ACC4)"},
	{0x0194, "Queenie (ACC4)"},
	{0x0195, "Fang (ACC4)"},
	{0x0196, "Frita (ACC4)"},
	{0x0197, "Tex (ACC4)"},
	{0x0198, "Melba (ACC4)"},
	{0x0199, "Bones (ACC4)"},
	{0x019A, "Anabelle (ACC4)"},
	{0x019B, "Rudy (ACC4)"},
	{0x019C, "Naomi (ACC4)"},
	{0x019D, "Peewee (ACC4)"},
	{0x019E, "Tammy (ACC4)"},
	{0x019F, "Olaf (ACC4)"},
	{0x01A0, "Lucy (ACC4)"},
	{0x01A1, "Elmer (ACC4)"},
	{0x01A2, "Puddles (ACC4)"},
	{0x01A3, "Rory (ACC4)"},
	{0x01A4, "Elise (ACC4)"},
	{0x01A5, "Walt (ACC4)"},
	{0x01A6, "Mira (ACC4)"},
	{0x01A7, "Pietro (ACC4)"},
	{0x01A8, "Aurora (ACC4)"},
	{0x01A9, "Papi (ACC4)"},
	{0x01AA, "Apple (ACC4)"},
	{0x01AB, "Rod (ACC4)"},
	{0x01AC, "Purrl (ACC4)"},
	{0x01AD, "Static (ACC4)"},
	{0x01AE, "Celia (ACC4)"},
	{0x01AF, "Zucker (ACC4)"},
	{0x01B0, "Peggy (ACC4)"},
	{0x01B1, "Ribbot (ACC4)"},
	{0x01B2, "Annalise (ACC4)"},
	{0x01B3, "Chow (ACC4)"},
	{0x01B4, "Sylvia (ACC4)"},
	{0x01B5, "Jacques (ACC4)"},
	{0x01B6, "Sally (ACC4)"},
	{0x01B7, "Doc (ACC4)"},
	{0x01B8, "Pompom (ACC4)"},
	{0x01B9, "Tank (ACC4)"},
	{0x01BA, "Becky (ACC4)"},
	{0x01BB, "Rizzo (ACC4)"},
	{0x01BC, "Sydney (ACC4)"},
	{0x01BD, "Barold (ACC4)"},
	{0x01BE, "Nibbles (ACC4)"},
	{0x01BF, "Kevin (ACC4)"},
	{0x01C0, "Gloria (ACC4)"},
	{0x01C1, "Lobo (ACC4)"},
	{0x01C2, "Hippeux (ACC4)"},
	{0x01C3, "Margie (ACC4)"},
	{0x01C4, "Lucky (ACC4)"},
	{0x01C5, "Rosie (ACC4)"},
	{0x01C6, "Rowan (ACC4)"},
	{0x01C7, "Maelle (ACC4)"},
	{0x01C8, "Bruce (ACC4)"},
	{0x01C9, "O'Hare (ACC4)"},
	{0x01CA, "Gayle (ACC4)"},
	{0x01CB, "Cranston (ACC4)"},
	{0x01CC, "Frobert (ACC4)"},
	{0x01CD, "Grizzly (ACC4)"},
	{0x01CE, "Cally (ACC4)"},
	{0x01CF, "Simon (ACC4)"},
	{0x01D0, "Iggly (ACC4)"},
	{0x01D1, "Angus (ACC4)"},
	{0x01D2, "Twiggy (ACC4)"},
	{0x01D3, "Robin (ACC4)"},
	{0x01D4, "Isabelle Promo (ACCP)"},
	{0x01D5, "Goldie (ACCP)"},
	{0x01D6, "Stitches (ACCP)"},
	{0x01D7, "Rosie (ACCP)"},
	{0x01D8, "K.K. Slider (ACCP)"},
	{0x0238, "Mario Classic Colors (3AM)"},
	{0x0239, "Mario Modern Colors (3AM)"},
	{0x023A, "Dark Hammer Slam Bowser (SKL)"},
	{0x023B, "Dark Turbo Charge Donkey Kong (SKL)"},
	{0x023D, "Mewtwo (SSB)"},
	{0x023E, "Mega Yarn Yoshi (YWW)"},
	{0x023F, "Isabelle (ACF)"},
	{0x0240, "K.K. Slider (ACF)"},
	{0x0241, "Mabel (ACF)"},
	{0x0242, "Tom Nook (ACF)"},
	{0x0243, "Digby (ACF)"},
	{0x0244, "Lottie (ACF)"},
	{0x0245, "Reese (ACF)"},
	{0x0246, "Cyrus (ACF)"},
	{0x0247, "Blathers (ACF)"},
	{0x0248, "Celeste (ACF)"},
	{0x0249, "Resetti (ACF)"},
	{0x024A, "Kicks (ACF)"},
	{0x024B, "Isabelle (Summer Outfit) (ACF)"},
	{0x024C, "Rover (ACF)"},
	{0x024D, "Timmy & Tommy (ACF)"},
	{0x024E, "Kapp'n (ACF)"},
	{0x024F, "Wolf Link (LOZ)"},
	{0x0250, "Shovel Knight (SHK)"},
	{0x0251, "Lucas (SSB)"},
	{0x0252, "Roy (SSB)"},
	{0x0253, "Ryu (SSB)"},
	{0x0254, "Kirby (KIR)"},
	{0x0255, "Meta Knight (KIR)"},
	{0x0256, "King Dedede (KIR)"},
	{0x0257, "Waddle Dee (KIR)"},
	{0x0258, "Mega Man (Gold Edition) (SSB)"},
	{0x025C, "Shadow Mewtwo (POK)"},
	{0x025D, "Callie (SPL)"},
	{0x025E, "Marie (SPL)"},
	{0x025F, "Inkling Girl (Lime Green) (SPL)"},
	{0x0260, "Inkling Boy (Purple) (SPL)"},
	{0x0261, "Inkling Squid (Orange) (SPL)"},
	{0x0262, "Rosalina (SMB)"},
	{0x0263, "Wario (SMB)"},
	{0x0264, "Donkey Kong (SMB)"},
	{0x0265, "Diddy Kong (SMB)"},
	{0x0266, "Daisy (SMB)"},
	{0x0267, "Waluigi (SMB)"},
	{0x0268, "Boo (SMB)"},
	{0x02E1, "One-Eyed Rathalos and Rider (Male) (MON)"},
	{0x02E2, "One-Eyed Rathalos and Rider (Female) (MON)"},
	{0x02E3, "Nabiru (MON)"},
	{0x02E4, "Rathian and Cheval (MON)"},
	{0x02E5, "Barioth and Ayuria (MON)"},
	{0x02E6, "Qurupeco and Dan (MON)"},
	{0x02E7, "Vivian (ACCW)"},
	{0x02E8, "Hopkins (ACCW)"},
	{0x02E9, "June (ACCW)"},
	{0x02EA, "Piper (ACCW)"},
	{0x02EB, "Paolo (ACCW)"},
	{0x02EC, "Hornsby (ACCW)"},
	{0x02ED, "Stella (ACCW)"},
	{0x02EE, "Tybalt (ACCW)"},
	{0x02EF, "Huck (ACCW)"},
	{0x02F0, "Sylvana (ACCW)"},
	{0x02F1, "Boris (ACCW)"},
	{0x02F2, "Wade (ACCW)"},
	{0x02F3, "Carrie (ACCW)"},
	{0x02F4, "Ketchup (ACCW)"},
	{0x02F5, "Rex (ACCW)"},
	{0x02F6, "Stu (ACCW)"},
	{0x02F7, "Ursala (ACCW)"},
	{0x02F8, "Jacob (ACCW)"},
	{0x02F9, "Maddie (ACCW)"},
	{0x02FA, "Billy (ACCW)"},
	{0x02FB, "Boyd (ACCW)"},
	{0x02FC, "Bitty (ACCW)"},
	{0x02FD, "Maggie (ACCW)"},
	{0x02FE, "Murphy (ACCW)"},
	{0x02FF, "Plucky (ACCW)"},
	{0x0300, "Sandy (ACCW)"},
	{0x0301, "Claude (ACCW)"},
	{0x0302, "Raddle (ACCW)"},
	{0x0303, "Julia (ACCW)"},
	{0x0304, "Louie (ACCW)"},
	{0x0305, "Bea (ACCW)"},
	{0x0306, "Admiral (ACCW)"},
	{0x0307, "Ellie (ACCW)"},
	{0x0308, "Boots (ACCW)"},
	{0x0309, "Weber (ACCW)"},
	{0x030A, "Candi (ACCW)"},
	{0x030B, "Leopold (ACCW)"},
	{0x030C, "Spike (ACCW)"},
	{0x030D, "Cashmere (ACCW)"},
	{0x030E, "Tad (ACCW)"},
	{0x030F, "Norma (ACCW)"},
	{0x0310, "Gonzo (ACCW)"},
	{0x0311, "Sprocket (ACCW)"},
	{0x0312, "Snooty (ACCW)"},
	{0x0313, "Olive (ACCW)"},
	{0x0314, "Dobie (ACCW)"},
	{0x0315, "Buzz (ACCW)"},
	{0x0316, "Cleo (ACCW)"},
	{0x0317, "Ike (ACCW)"},
	{0x0318, "Tasha (ACCW)"},
	{0x0319, "Rilla (ACCS)"},
	{0x031A, "Marty (ACCS)"},
	{0x031B, "Étoile (ACCS)"},
	{0x031C, "Chai (ACCS)"},
	{0x031D, "Chelsea (ACCS)"},
	{0x031E, "Toby (ACCS)"},
	{0x034B, "Link (Ocarina of Time) (LOZ)"},
	{0x034F, "8-bit Link (The Legend of Zelda) (LOZ)"},
	{0x0350, "Toon Link (The Wind Waker) (LOZ)"},
	{0x0352, "Toon Zelda (The Wind Waker) (LOZ)"},
	{0x034C, "Link (Majora's Mask) (LOZ)"},
	{0x034D, "Link (Twilight Princess) (LOZ)"},
	{0x034E, "Link (Skyward Sword) (LOZ)"},
	{0x0353, "Link (Archer) (BOTW)"},
	{0x0354, "Link (Rider) (BOTW)"},
	{0x0355, "Guardian (BOTW)"},
	{0x0356, "Zelda (BOTW)"},
	{0x035C, "Bokoblin (BOTW)"},
	{0x0269,"Mario - Soccer (MSS)"},
	{0x026A,"Mario - Baseball (MSS)"},
	{0x026B,"Mario - Tennis (MSS)"},
	{0x026C,"Mario - Golf (MSS)"},
	{0x026D,"Mario - Horse Racing (MSS)"},
	{0x026E,"Luigi - Soccer (MSS)"},
	{0x026F,"Luigi - Baseball (MSS)"},
	{0x0270,"Luigi - Tennis (MSS)"},
	{0x0271,"Luigi - Golf (MSS)"},
	{0x0272,"Luigi - Horse Racing (MSS)"},
	{0x0273,"Peach - Soccer (MSS)"},
	{0x0274,"Peach - Baseball (MSS)"},
	{0x0275,"Peach - Tennis (MSS)"},
	{0x0276,"Peach - Golf (MSS)"},
	{0x0277,"Peach - Horse Racing (MSS)"},
	{0x0278,"Daisy - Soccer (MSS)"},
	{0x0279,"Daisy - Baseball (MSS)"},
	{0x027A,"Daisy - Tennis (MSS)"},
	{0x027B,"Daisy - Golf (MSS)"},
	{0x027C,"Daisy - Horse Racing (MSS)"},
	{0x027D,"Yoshi - Soccer (MSS)"},
	{0x027E,"Yoshi - Baseball (MSS)"},
	{0x027F,"Yoshi - Tennis (MSS)"},
	{0x0280,"Yoshi - Golf (MSS)"},
	{0x0281,"Yoshi - Horse Racing (MSS)"},
	{0x0282,"Wario - Soccer (MSS)"},
	{0x0283,"Wario - Baseball (MSS)"},
	{0x0284,"Wario - Tennis (MSS)"},
	{0x0285,"Wario - Golf (MSS)"},
	{0x0286,"Wario - Horse Racing (MSS)"},
	{0x0287,"Waluigi - Soccer (MSS)"},
	{0x0288,"Waluigi - Baseball (MSS)"},
	{0x0289,"Waluigi - Tennis (MSS)"},
	{0x028A,"Waluigi - Golf (MSS)"},
	{0x028B,"Waluigi - Horse Racing (MSS)"},
	{0x028C,"Donkey Kong - Soccer (MSS)"},
	{0x028D,"Donkey Kong - Baseball (MSS)"},
	{0x028E,"Donkey Kong - Tennis (MSS)"},
	{0x028F,"Donkey Kong - Golf (MSS)"},
	{0x0290,"Donkey Kong - Horse Racing (MSS)"},
	{0x0291,"Diddy Kong - Soccer (MSS)"},
	{0x0292,"Diddy Kong - Baseball (MSS)"},
	{0x0293,"Diddy Kong - Tennis (MSS)"},
	{0x0294,"Diddy Kong - Golf (MSS)"},
	{0x0295,"Diddy Kong - Horse Racing (MSS)"},
	{0x0296,"Bowser - Soccer (MSS)"},
	{0x0297,"Bowser - Baseball (MSS)"},
	{0x0298,"Bowser - Tennis (MSS)"},
	{0x0299,"Bowser - Golf (MSS)"},
	{0x029A,"Bowser - Horse Racing (MSS)"},
	{0x029B,"Bowser Jr. - Soccer (MSS)"},
	{0x029C,"Bowser Jr. - Baseball (MSS)"},
	{0x029D,"Bowser Jr. - Tennis (MSS)"},
	{0x029E,"Bowser Jr. - Golf (MSS)"},
	{0x029F,"Bowser Jr. - Horse Racing (MSS)"},
	{0x02A0,"Boo - Soccer (MSS)"},
	{0x02A1,"Boo - Baseball (MSS)"},
	{0x02A2,"Boo - Tennis (MSS)"},
	{0x02A3,"Boo - Golf (MSS)"},
	{0x02A4,"Boo - Horse Racing (MSS)"},
	{0x02A5,"Baby Mario - Soccer (MSS)"},
	{0x02A6,"Baby Mario - Baseball (MSS)"},
	{0x02A7,"Baby Mario - Tennis (MSS)"},
	{0x02A8,"Baby Mario - Golf (MSS)"},
	{0x02A9,"Baby Mario - Horse Racing (MSS)"},
	{0x02AA,"Baby Luigi - Soccer (MSS)"},
	{0x02AB,"Baby Luigi - Baseball (MSS)"},
	{0x02AC,"Baby Luigi - Tennis (MSS)"},
	{0x02AD,"Baby Luigi - Golf (MSS)"},
	{0x02AE,"Baby Luigi - Horse Racing (MSS)"},
	{0x02AF,"Birdo - Soccer (MSS)"},
	{0x02B0,"Birdo - Baseball (MSS)"},
	{0x02B1,"Birdo - Tennis (MSS)"},
	{0x02B2,"Birdo - Golf (MSS)"},
	{0x02B3,"Birdo - Horse Racing (MSS)"},
	{0x02B4,"Rosalina - Soccer (MSS)"},
	{0x02B5,"Rosalina - Baseball (MSS)"},
	{0x02B6,"Rosalina - Tennis (MSS)"},
	{0x02B7,"Rosalina - Golf (MSS)"},
	{0x02B8,"Rosalina - Horse Racing (MSS)"},
	{0x02B9,"Metal Mario - Soccer (MSS)"},
	{0x02BA,"Metal Mario - Baseball (MSS)"},
	{0x02BB,"Metal Mario - Tennis (MSS)"},
	{0x02BC,"Metal Mario - Golf (MSS)"},
	{0x02BD,"Metal Mario - Horse Racing (MSS)"},
	{0x02BE,"Pink Gold Peach - Soccer (MSS)"},
	{0x02BF,"Pink Gold Peach - Baseball (MSS)"},
	{0x02C0,"Pink Gold Peach - Tennis (MSS)"},
	{0x02C1,"Pink Gold Peach - Golf (MSS)"},
	{0x02C2,"Pink Gold Peach - Horse Racing (MSS)"},
};

struct AmiiboIdStruct* parseCharData(const u8* data) {
	static struct AmiiboIdStruct result;
	
	int brand = (data[0x00] & 0xFF) << 8;
	brand |= (data[0x01] & 0xFF);

	int variant = data[0x02] & 0xFF;

	int type = data[0x03] & 0xFF;

	int amiiboId = (data[0x04] & 0xFF) << 8;
	amiiboId |= (data[0x05] & 0xFF);

	int series = (data[0x06] & 0xFF) << 8;
	series |= (data[0x07] & 0xFF);
	
	result.brand = brand;
	result.variant = variant;
	result.type = type;
	result.amiiboId = amiiboId;
	result.series = series;

	return &result;
}

int getNameByAmiiboId(u16 id, char *name, int length) {
	auto res = idList.find(id);
	if (res == idList.end())
		return 0;
	const char *val = (*res).second;
	int len = strlen(val);
	if (len >= length)
		return 0;
	
	strcpy(name, val);
	return len;
}