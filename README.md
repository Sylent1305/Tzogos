# Tzogous 37 — Player Guide

**Tzogous 37** is a fast-paced, poker-inspired card game focused on bluffing, tactical joker usage, and bonus-based scoring. The game features structured betting rounds with **pot-limit** rules, where each player's maximum raise is limited to the current pot size.

---

## Table of Contents

1. [Game Flow](#game-flow)  
2. [Pot-Limit Betting](#pot-limit-betting)  
3. [Player Actions](#player-actions)  
4. [Joker Rules](#joker-rules)  
5. [Card Values](#card-values)  
6. [Scoring](#scoring)  
7. [Tie Breaker](#tie-breaker)  
8. [Hand Probability (Reference)](#hand-probability-reference)  
9. [Best Two-Card Hand from Seven Cards](#best-two-card-hand-from-seven-cards)  
10. [Optional Variants](#optional-variants)  
11. [Example Round Summary](#example-round-summary)  
12. [License](#license)  

---

## Game Flow

Each game consists of multiple rounds, played in cycles. A cycle includes four rounds, with players gradually using up their cards:

### Round Structure

1. Deal **7 cards** to each player.  
2. Each player selects and places **1 face-down card**.  
3. **First betting round** (Pot-Limit): Check / Raise / Call / Fold.  
4. Remaining players place **1 face-up card**.  
5. **Second betting round** (Pot-Limit).  
6. Reveal both cards → Calculate score → Highest hand wins the pot.  
7. In case of a tie, perform a [tie-breaker draw](#tie-breaker).

Players do **not draw** new cards between rounds.

### Game Cycle (Card Countdown)

| Round | Cards in Hand | Notes                        |
|-------|----------------|------------------------------|
| 1     | 7              | Standard round               |
| 2     | 5              | Standard round               |
| 3     | 3              | Standard round               |
| 4     | 1              | Final Round with community card |

### Final Round Rules

- Players place their final card **face down**.  
- A **community card** is drawn from the deck and placed **face up**.  
- One betting round is held.  
- Players reveal cards and score using the face-down card + community card.  
- Winner takes the pot.  
- Deck is reshuffled, and a new cycle begins.

---

## Pot-Limit Betting

- A raise may **not exceed** the size of the current pot.  
- Minimum raise must match the previous bet or raise.  
- Two betting rounds per hand: after face-down and face-up cards.

> Example: If the pot is 20 chips, the maximum raise is 20.

---

## Player Actions

- **Check** – Pass without betting (only allowed if no bet is active).  
- **Raise** – Bet any amount up to the pot size.  
- **Call** – Match the current highest bet.  
- **Fold** – Forfeit your hand and exit the round.

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
> - Only the highest applicable bonus is counted.  
> - A Straight Flush replaces both the Straight and Flush bonuses.

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

- **Two-Deck Mode**: Enables a bonus for “Pair + Suit” (treat as +10 points).  
- **Joker Limit**: Restrict each player to one joker use per round or per game.  
- **Sudden Death**: After three tie-break draws, split the pot.

---

## Example Round Summary

**2-Player Example (Round 1 of Cycle)**

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
