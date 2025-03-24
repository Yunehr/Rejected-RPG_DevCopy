#include "Unity/src/unity.h"
#include "Unity/src/unity_internals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../Storyline.h"
#include "../../PlayerCharacter.h"
#include "../../RNG.h"

// Mock Sleep to avoid actual delay
#define Sleep(x) ((void)0)

// Mocks and helpers
static FILE* original_stdin;
static FILE* original_stdout;
static FILE* test_input;
static FILE* test_output;
static char output_buffer[2048];

void setUp(void) {
    // Redirect stdout to capture output
    test_output = freopen("test_output.txt", "w", stdout);
    memset(output_buffer, 0, sizeof(output_buffer));
}

void tearDown(void) {
    // Restore stdout
    freopen("CON", "w", stdout);
    if (test_output) fclose(test_output);
    test_output = NULL;
}

// STORY-001: getUserChoice valid/invalid
void test_getUserChoice_valid_then_invalid_input(void) {
    test_input = freopen("test_input.txt", "w", stdin);
    fprintf(test_input, "10\nabc\n2\n");
    fclose(test_input);
    test_input = freopen("test_input.txt", "r", stdin);

    int choice = getUserChoice(1, 3);
    TEST_ASSERT_EQUAL(2, choice);

    freopen("CON", "r", stdin); // Reset stdin
}

// STORY-002: checkPoint
void test_checkPoint_updates_and_ignores_zero(void) {
    int val1 = checkPoint(1);
    TEST_ASSERT_EQUAL(1, val1);

    int val2 = checkPoint(3);
    TEST_ASSERT_EQUAL(3, val2);

    int val3 = checkPoint(0);
    TEST_ASSERT_EQUAL(3, val3);
}

// STORY-003: storyBegins() output
void test_storyBegins_outputs_correctly(void) {
    PC testPlayer = setCharacter(0);
    test_input = freopen("test_input.txt", "w", stdin);
    fprintf(test_input, "1\n");
    fclose(test_input);
    test_input = freopen("test_input.txt", "r", stdin);

    storyBegins(&testPlayer);

    freopen("test_output.txt", "r", test_output);
    fread(output_buffer, 1, sizeof(output_buffer), test_output);

    TEST_ASSERT_NOT_NULL(strstr(output_buffer, "You wake up in the middle of the woods"));
    TEST_ASSERT_NOT_NULL(strstr(output_buffer, "Which way do you go?"));
    TEST_ASSERT_NOT_NULL(strstr(output_buffer, "Your adventure begins!"));
}

// STORY-004: storyBeginsAgain recursion check
void test_storyBeginsAgain_avoids_infinite_recursion(void) {
    PC testPlayer = setCharacter(1);
    test_input = freopen("test_input.txt", "w", stdin);
    fprintf(test_input, "2\n2\n2\n1\n"); // Eventually exit loop
    fclose(test_input);
    test_input = freopen("test_input.txt", "r", stdin);

    storyBeginsAgain(&testPlayer);
    TEST_ASSERT_EQUAL(100, checkPoint(0));
}

// STORY-006: actThree decreases HP
void test_actThree_decreases_HP_on_choice_2(void) {
    PC testPlayer = setCharacter(2);
    int originalHP = testPlayer.stats[HP];

    test_input = freopen("test_input.txt", "w", stdin);
    fprintf(test_input, "2\n"); // Look into mirror (-HP)
    fclose(test_input);
    test_input = freopen("test_input.txt", "r", stdin);

    actThree(&testPlayer);
    TEST_ASSERT_TRUE(testPlayer.stats[HP] < originalHP);
}

// STORY-007: RNG randomness check
void test_rng_randomness(void) {
    int different = 0;
    int prev = RNG(5, 1);
    for (int i = 0; i < 10; ++i) {
        int val = RNG(5, 1);
        if (val != prev) {
            different = 1;
            break;
        }
    }
    TEST_ASSERT_TRUE(different);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_getUserChoice_valid_then_invalid_input);
    RUN_TEST(test_checkPoint_updates_and_ignores_zero);
    RUN_TEST(test_storyBegins_outputs_correctly);
    RUN_TEST(test_storyBeginsAgain_avoids_infinite_recursion);
    RUN_TEST(test_actThree_decreases_HP_on_choice_2);
    RUN_TEST(test_rng_randomness);
    return UNITY_END();
}
