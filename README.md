# Tzogous 37 — Player Guide

**Tzogous 37** is a fast-paced, poker-inspired card game focused on bluffing, tactical joker usage, and bonus-based scoring. The game features structured betting rounds with **pot-limit** rules, where each player's maximum raise is limited to the current pot size.

---

## Table of Contents

1. [Game Flow](#game-flow)  
2. [Pot-Limit Betting](#pot-limit-betting)  
3. [Player Actions](#player-actions)  
4. [Folding Rules](#folding-rules)  
5. [Joker Rules](#joker-rules)  
6. [Card Values](#card-values)  
7. [Scoring](#scoring)  
8. [Tie Breaker](#tie-breaker)  
9. [Hand Probability (Reference)](#hand-probability-reference)  
10. [Best Two-Card Hand from Seven Cards](#best-two-card-hand-from-seven-cards)  
11. [Optional Variants](#optional-variants)  
12. [Example Round Summary](#example-round-summary)  
13. [License](#license)  

---

## Game Flow

Each **hand** consists of **four rounds**, with players gradually using up their cards. A hand ends when all four rounds are played, and then a new hand begins with a new 7-card hand per player.

### Round Structure (Per Hand)

| Round | Card Play Style                                    | Notes                              |
|-------|-----------------------------------------------------|-------------------------------------|
| 1     | **First card face-down**, then **second face-up**  | Standard round                      |
| 2     | **Both cards face-down**                           | Hidden showdown                     |
| 3     | **First card face-up**, then **second face-down**  | Reverse of Round 1                  |
| 4     | **One card face-down** + **1 community card**      | Final round, with shared card       |

Each round follows this structure:

1. All players place an **ante** (small forced bet).  
2. Card placement based on round style.  
3. **First betting round** (Pot-Limit).  
4. After both cards are placed, **second betting round**.  
5. Cards are revealed → Scores calculated → Highest score wins the pot.  
6. In case of a tie, perform a [tie-breaker draw](#tie-breaker).  

> Players **do not draw new cards** during the hand.  
> After 4 rounds, the hand ends, and a new hand begins with new cards.

> ⚠️ **Folding Rule**: If a player folds **after placing only one card**, they must **discard** an additional card from their hand immediately, following the round’s placement rules (face-up or face-down). This keeps the game state balanced.

---

## Pot-Limit Betting

- A raise may **not exceed** the size of the current pot.  
- Minimum raise must match the previous bet or raise.  
- Two betting rounds per hand: after each card placement.

> Example: If the pot is 20 chips, the maximum raise is 20.

---

## Player Actions

- **Check** – Pass without betting (only allowed if no bet is active).  
- **Raise** – Bet any amount up to the pot size.  
- **Call** – Match the current highest bet.  
- **Fold** – Forfeit your hand and exit the round (see [Folding Rules](#folding-rules)).

---

## Folding Rules

When a player **folds**, they give up the chance to win the pot. However:

- **Cards already placed** remain on the table and **can still be affected by jokers**.
- If the player folded **after placing only one card**, they must:
  - **Immediately discard** an additional card from their hand.
  - This card must match the round's placement rule (**face-down or face-up**).
- Folded players take no further actions in the round.

> 🃏 Jokers can still swap with **folded player’s cards**.  
> 🎯 This preserves the board and strategic elements even after a fold.

---

## Joker Rules

- A joker may be used **before taking your action**.  
- Using a joker allows you to **replace** one card (face-down or face-up) of an opponent with one card from your own hand.  
- After using a joker, **draw 1 card** from the deck to restore your hand to 7 cards.

> Jokers have a value of 0 and are used purely for tactical disruption.

---

## Card Values

| Card   | Value     |
|--------|-----------|
| 2–10   | Face value |
| J      | 11        |
| Q      | 12        |
| K      | 13        |
| A      | 14        |
| Joker  | 0         |

---

## Scoring

Each player scores based on the **sum of their two played cards**, plus **one applicable bonus**.

### Bonus Combinations

| Combination             | Bonus Points |
|-------------------------|--------------|
| Flush (same suit)       | +3           |
| Straight (consecutive)  | +5           |
| Pair (same rank)        | +7           |
| Straight Flush          | +10          |

> Notes:
> - A straight may be A–2 (Ace counts as low).  
> - Only the **highest** applicable bonus is counted.  
> - A **Straight Flush** replaces both the Straight and Flush bonuses.

### Examples

- **Flush only**:  
  10♥ + Q♥ → (10 + 12) + 3 = **25**

- **Straight only**:  
  J♣ + Q♦ → (11 + 12) + 5 = **28**

- **Straight Flush**:  
  J♥ + Q♥ → (11 + 12) + 10 = **33**

---

## Tie Breaker

In case of a scoring tie:

1. Each tied player draws one card from the deck.  
2. Highest card wins the pot.  
3. If tied again, repeat the draw.

---

## Hand Probability (Reference)

Approximate probability of receiving specific two-card combinations from a full deck:

| Combination       | Count | Probability (%) |
|-------------------|------:|----------------:|
| Pair              |    78 |            5.88 |
| Flush (non-SF)    |   264 |           19.91 |
| Straight (non-SF) |   144 |           10.86 |
| Straight Flush    |    48 |            3.62 |
| High Card         |   792 |           59.73 |

> Definitions:  
> - *Flush (non-SF)*: Same suit, not consecutive.  
> - *Straight (non-SF)*: Consecutive rank, different suits.

---

## Best Two-Card Hand from Seven Cards

Based on a simulation of 100,000 hands, these are the likelihoods of the **best two-card combo** in a 7-card hand:

| Category         | Probability (%) |
|------------------|-----------------|
| Straight Flush   | 60.55           |
| Straight         | 35.96           |
| Flush            | 3.49            |
| Pair             | <0.01           |
| High Card        | <0.01           |

> These probabilities help guide which cards to prioritize or discard.

---

## Optional Variants

- **Two-Deck Mode**: Enables a bonus for “Pair + Suit” (treat as +12 points).  
- **Joker Limit**: Restrict each player to one joker use per hand.  
- **Sudden Death**: After one tie-break draw, split the pot.

---

## Example Round Summary

**2-Player Example (Round 1 of Hand)**

1. Both players ante 5 chips → pot = 10  
2. Each receives 7 cards  
3. Player A plays face-down 9♦; Player B plays face-down Q♠  
4. **First Betting Round**  
   - Player A raises 10 → pot = 20  
   - Player B calls → pot = 30  
5. Players reveal face-up cards  
   - Player A: K♣  
   - Player B: Q♥  
6. **Second Betting Round**  
   - Player B raises 30 → pot = 60  
   - Player A calls → pot = 90  
7. **Reveal**  
   - Player A: 9♦ + K♣ = 22  
   - Player B: Q♠ + Q♥ = 24 + 7 (pair bonus) = **31**  
   - **Player B wins 90 chips**

---

## License

Distributed under the **MIT License**.  
See the `LICENSE` file for full license details.
