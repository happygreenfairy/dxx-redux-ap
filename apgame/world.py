# Far as I can tell, this file seem feasible to hand write, whereas it seems like it's the other files that I should
# plan around auto-generating the logic for and whatnot.
# Maybe I'm doing this wrong though, I'm still learning built off how apquest does things...

# this is pretty much just me doing the stuff that apquest does at the start for now while I'm still figuring out
# what I actually like, *need* to do.
# I'll probably start cross-referencing how Doom, and maybe also Tyrian, do things if I need to, though.
from collections.abc import Mapping
from typing import Any

from worlds.AutoWorld import World

# Yeah, I know, I haven't made these files yet, but I'm going to have this here anyway.
# I know it's going to be a bit before this thing is playable, this is just me preparing in advance.
# Just thought I'd try to counter some of my forgetfulness with doing this now and all that.
# It's going to be kind of funny if that backfires and my forgetfulness makes this actually detrimental to write now.
from . import items, locations, options, regions, rules, web_world

# Yeah so I understand this part to be pretty important to have.
class APDescent(World):
    """
    Released in 1994 (shareware)/1995 (full game), Descent is not your everyday '90s FPS!
    In Descent, 6 degrees of freedom means you get to move and rotate in any combination of directions at any time!
    Good thing, too. You'll need all the help you can get in these outerspace caverns filled with rogue mining robots.
    WARNING: Randomizer not recommended for players not already familiar with both Archipelago and Descent!
    Even on trainee, some levels are incredibly difficult if you're even slightly under-equipped.
    Settings exist to try to help account for this, but they'll only get you so far.
    """
    # I'll probably change and shorten this once I actually have a better feel for what this plays like.
    # For now, I'd rather have the warning in there just in case it's as hard as I'm expecting it to be.
    # Like... look. I have finished The Plutonia Experiment on normal and I *still* can't finish Descent 1.
    # I cannot exactly stress enough how much I'm expecting this to be a nightmare for anybody not prepared for it.
    
    game = "Descent"
    
    # This class apparently helps define how this will display on the website.
    web = web_world.APDescentWebWorld()
    
    # And this is related to stuff defined in options.py, a file I haven't made yet as of writing.
    options_dataclass = options.APDescentOptions
    # Apparently a common mistake below this is to use an equals sign instead of a colon.
    # ...not sure why you're reading this instead of APQuest if you're new to writing APWorlds though.
    # I don't know what I'm doing! The dev of that does! Read that one instead.
    options: options.ApDescentOptions
    
    # This is related to stuff that will be defined in regions.py and items.py
    location_name_to_id = locations.LOCATION_NAME_TO_ID
    item_name_to_id = items.ITEM_NAME_TO_ID
    
    # This is a region that can always be gone back to. Can you tell I'm using these to write notes for myself?
    origin_region_name = "LevelSelect"
    
    # I'll write the rest after I make the other files I need to be making.
    # Some of which I need to find a way to generate instead of writing by hand.